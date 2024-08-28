package com.example.speak2sign.view

import android.content.ContentValues.TAG
import android.content.Intent
import android.os.Bundle
import android.text.SpannableString
import android.text.Spanned
import android.text.style.ClickableSpan
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.speak2sign.R
import com.example.speak2sign.model.User
import com.google.firebase.Firebase
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseAuthUserCollisionException
import com.google.firebase.auth.FirebaseUser
import com.google.firebase.auth.auth
import com.google.firebase.firestore.FirebaseFirestore


class SignUp : AppCompatActivity() {

    // Initialize variables for UI elements
    private lateinit var nameEt: EditText
    private lateinit var emailEt: EditText
    private lateinit var phoneEt: EditText
    private lateinit var passEt: EditText
    private lateinit var signUpButton: Button

    // Initialize FirebaseAuth and Firestore
    private lateinit var firebaseAuth: FirebaseAuth
    private val firestore: FirebaseFirestore = FirebaseFirestore.getInstance()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sign_up)

        // Connect variables with UI elements
        nameEt = findViewById(R.id.textInputEditNama)
        emailEt = findViewById(R.id.textInputEditEmail)
        phoneEt = findViewById(R.id.textInputEditPhone)
        passEt = findViewById(R.id.editTextPassword2)
        signUpButton = findViewById(R.id.buttonSignup)

        // Get FirebaseAuth instance
        firebaseAuth = FirebaseAuth.getInstance()

        // Set onClickListener for the sign-up button
        signUpButton.setOnClickListener {
            // Get text from EditText
            val name = nameEt.text.toString()
            val email = emailEt.text.toString()
            val phone = phoneEt.text.toString()
            val pass = passEt.text.toString()

            // Validate input
            if (name.isNotEmpty() && email.isNotEmpty() && phone.isNotEmpty() && pass.isNotEmpty()) {
                if (pass.length >= 8) {
                    // Create a new user with email and password
                    firebaseAuth.createUserWithEmailAndPassword(email, pass).addOnCompleteListener { task ->
                        if (task.isSuccessful) {
                            // Get the newly registered user
                            val user = firebaseAuth.currentUser
                            user?.let {
                                val userId = it.uid
                                // Create a new user object
                                val newUser = User(id = userId, name = name, phone = phone, role = "user")
                                // Save the new user data in Firestore
                                firestore.collection("users").document(userId).set(newUser)
                                    .addOnSuccessListener {
                                        Toast.makeText(this, "Register Success, check your email to LOGIN", Toast.LENGTH_SHORT).show()
                                        val user = Firebase.auth.currentUser!!
                                        user!!.sendEmailVerification()
                                            .addOnCompleteListener { task ->
                                                if (task.isSuccessful) {
                                                    Log.d(TAG, "Email sent.")
                                                }
                                            }
                                    }
                                    .addOnFailureListener { e ->
                                        Log.e("FirestoreError", "Failed to add user data: ", e)
                                        user.delete()
                                        NotificationDialog.showDialog(this, "Register Failed", "Please fill the requirement!")
                                    }
                            }
                        } else {
                            // Handle error cases during registration
                            if (task.exception is FirebaseAuthUserCollisionException) {
                                NotificationDialog.showDialog(this, "Email already in use", "Please use a different email")
                            } else {
                                NotificationDialog.showDialog(this, "Register Failed", "Try again")
                            }
                        }
                    }
                } else {
                    NotificationDialog.showDialog(this, "Error", "Password must be at least 8 characters")
                }
            } else {
                NotificationDialog.showDialog(this, "Error", "Empty Fields Are Not Allowed !!")
            }
        }

        // Initialize TextView for the text "Already have an account? Sign in"
        val textView = findViewById<TextView>(R.id.signin)
        val text = "Already have accounts? Sign in"
        val spannableString = SpannableString(text)

        // Make the "Sign in" text clickable
        val clickableSpan = object : ClickableSpan() {
            override fun onClick(widget: View) {
                val intent = Intent(this@SignUp, SignIn::class.java)
                startActivity(intent)
            }
        }

        spannableString.setSpan(clickableSpan, 23, 30, Spanned.SPAN_EXCLUSIVE_EXCLUSIVE)
        textView.text = spannableString
        textView.movementMethod = android.text.method.LinkMovementMethod.getInstance()
    }

    // Function to send email verification
    private fun sendEmailVerification(user: FirebaseUser) {
        user.sendEmailVerification().addOnCompleteListener { task ->
            if (task.isSuccessful) {
                Toast.makeText(this, "Verification email sent. Please check your email to LOGIN.", Toast.LENGTH_LONG).show()
                val intent = Intent(this, SignIn::class.java)
                startActivity(intent)
            } else {
                Toast.makeText(this, "Failed to send verification email.", Toast.LENGTH_SHORT).show()
            }
        }
    }

    companion object {
        private fun sendEmailVerification(signUp: SignUp, user: FirebaseUser) {
            user.sendEmailVerification().addOnCompleteListener { task ->
                if (task.isSuccessful) {
                    Toast.makeText(signUp, "Verification email sent. Please check your email to LOGIN.", Toast.LENGTH_LONG).show()
                    val intent = Intent(signUp, SignIn::class.java)
                    signUp.startActivity(intent)
                    signUp.finish()  // To prevent the user from going back to the sign-up page
                } else {
                    val errorMessage = task.exception?.localizedMessage ?: "Failed to send verification email."
                    Log.e("EmailVerification", errorMessage)
                    Toast.makeText(signUp, errorMessage, Toast.LENGTH_SHORT).show()
                }
            }
        }
    }
}