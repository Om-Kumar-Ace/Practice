package com.example.speaksign

import android.app.Activity
import android.content.Intent
import android.graphics.Bitmap
import android.os.Bundle
import android.speech.RecognizerIntent
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import android.widget.VideoView
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.ktx.Firebase
import com.google.firebase.storage.FirebaseStorage
import com.google.firebase.storage.ktx.storage
import com.google.mlkit.vision.common.InputImage
import com.google.mlkit.vision.objects.ObjectDetection
import com.google.mlkit.vision.objects.defaults.ObjectDetectorOptions
import com.google.mlkit.vision.text.TextRecognition
import com.google.mlkit.vision.text.latin.TextRecognizerOptions
import com.google.mlkit.nl.languageid.LanguageIdentification
import com.google.mlkit.nl.languageid.LanguageIdentificationOptions

class MainActivity : AppCompatActivity() {

    private lateinit var textView: TextView
    private lateinit var videoView: VideoView
    private lateinit var imageView: ImageView
    private lateinit var speechButton: Button
    private lateinit var imageButton: Button

    private val storage: FirebaseStorage = Firebase.storage

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        textView = findViewById(R.id.textView)
        videoView = findViewById(R.id.videoView)
        imageView = findViewById(R.id.imageView)
        speechButton = findViewById(R.id.speechButton)
        imageButton = findViewById(R.id.imageButton)

        speechButton.setOnClickListener {
            startSpeechRecognition()
        }

        imageButton.setOnClickListener {
            pickImageFromGallery()
        }
    }

    // 1. Text to Sign (ASL Language)
    private fun translateTextToASL(text: String) {
        val words = text.split(" ")
        for (word in words) {
            val aslVideoRef = storage.reference.child("asl_videos/$word.mp4")
            aslVideoRef.downloadUrl.addOnSuccessListener { uri ->
                videoView.setVideoURI(uri)
                videoView.start()
            }.addOnFailureListener {
                textView.text = "Video not found for word: $word"
            }
        }
    }

    // 2. Image to Sign (ASL Language)
    private val imagePickerLauncher = registerForActivityResult(
        ActivityResultContracts.StartActivityForResult()
    ) { result ->
        if (result.resultCode == Activity.RESULT_OK) {
            val uri = result.data?.data
            imageView.setImageURI(uri)
            uri?.let { processImageForText(it) }
        }
    }

    private fun pickImageFromGallery() {
        val intent = Intent(Intent.ACTION_PICK)
        intent.type = "image/*"
        imagePickerLauncher.launch(intent)
    }

    private fun processImageForText(uri: android.net.Uri) {
        val image = InputImage.fromFilePath(this, uri)
        val recognizer = TextRecognition.getClient(TextRecognizerOptions.DEFAULT_OPTIONS)
        recognizer.process(image)
            .addOnSuccessListener { visionText ->
                translateTextToASL(visionText.text)
            }
            .addOnFailureListener {
                textView.text = "Failed to recognize text from image."
            }
    }

    // 3. Voice to Sign (ASL Language)
    private val speechRecognitionLauncher = registerForActivityResult(
        ActivityResultContracts.StartActivityForResult()
    ) { result ->
        if (result.resultCode == RESULT_OK && result.data != null) {
            val matches = result.data?.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS)
            matches?.firstOrNull()?.let {
                identifyLanguage(it)
            }
        }
    }

    private fun startSpeechRecognition() {
        val intent = Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH).apply {
            putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM)
            putExtra(RecognizerIntent.EXTRA_LANGUAGE, "en-US")
        }
        speechRecognitionLauncher.launch(intent)
    }

    // 4. Sign to Text (Simplified Example)
    private fun processGesture(videoFrame: Bitmap) {
        // Pseudo-code: Recognize gesture from video frame and convert to text
        // Use a pre-trained model to recognize the gesture
        val recognizedText = "Mock Gesture Recognition" // Replace with actual recognition logic
        textView.text = recognizedText
    }

    // 5. Object Detection
    private fun runObjectDetection(bitmap: Bitmap) {
        val image = InputImage.fromBitmap(bitmap, 0)
        val options = ObjectDetectorOptions.Builder()
            .setDetectorMode(ObjectDetectorOptions.SINGLE_IMAGE_MODE)
            .enableClassification()  // Optional: Enable classification
            .build()
        val detector = ObjectDetection.getClient(options)
        detector.process(image)
            .addOnSuccessListener { detectedObjects ->
                for (obj in detectedObjects) {
                    // Draw bounding boxes and labels on the imageView or overlay
                    textView.text = "Detected object: ${obj.labels.firstOrNull()?.text ?: "Unknown"}"
                }
            }
            .addOnFailureListener {
                textView.text = "Object detection failed."
            }
    }

    // 6. Language Identification
    private fun identifyLanguage(text: String) {
        val languageIdentifier = LanguageIdentification.getClient(
            LanguageIdentificationOptions.Builder().setConfidenceThreshold(0.5f).build()
        )
        languageIdentifier.identifyLanguage(text)
            .addOnSuccessListener { languageCode ->
                if (languageCode == "und") {
                    textView.text = "Cannot identify language."
                } else {
                    textView.text = "Language: $languageCode"
                    translateTextToASL(text)
                }
            }
            .addOnFailureListener {
                textView.text = "Language identification failed."
            }
    }
}
