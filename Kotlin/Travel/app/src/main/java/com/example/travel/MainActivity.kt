package com.example.travel

import android.media.Image
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import androidx.activity.ComponentActivity


class MainActivity : ComponentActivity() {

    private var currentimage = 0
    lateinit var image : ImageView
    var places = arrayOf("India Gate","Red Fort","Humayun’s Tomb","Tomb")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val next = findViewById<Button>(R.id.btn_next)
        val prev = findViewById<Button>(R.id.btn_prev)
        val placeName = findViewById<TextView>(R.id.tVname)

        next.setOnClickListener {
            var idCurrentImageString= """pic$currentimage"""

            var idCurrentImageInt = this.resources.getIdentifier(idCurrentImageString,"id",packageName)
            image=findViewById(idCurrentImageInt)
            image.alpha=0f
            currentimage=(4+currentimage+1)%4
            var idImageToShowString="pic"+currentimage
            var idImageToShowInt = this.resources.getIdentifier(idImageToShowString,"id",packageName)
            image=findViewById(idImageToShowInt)
            image.alpha=1f
            placeName.text=places[currentimage]
        }
        prev.setOnClickListener {
            var idCurrentImageString= """pic$currentimage"""

            var idCurrentImageInt = this.resources.getIdentifier(idCurrentImageString,"id",packageName)
            image=findViewById(idCurrentImageInt)
            image.alpha=0f
            currentimage=(4+currentimage-1)%4
            var idImageToShowString="pic"+currentimage
            var idImageToShowInt = this.resources.getIdentifier(idImageToShowString,"id",packageName)
            image=findViewById(idImageToShowInt)
            image.alpha=1f
            placeName.text=places[currentimage]
        }
    }
}

