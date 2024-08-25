package com.example.myapplication

import android.os.Bundle
import android.widget.Button
import android.widget.LinearLayout
import androidx.activity.ComponentActivity


class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val buttonHot = findViewById<Button>(R.id.btnHOT)
        val buttonCOOL = findViewById<Button>(R.id.btnCOOL)
        val LinearLayout = findViewById<LinearLayout>(R.id.LinearLayout)
        buttonHot.setOnClickListener{
            LinearLayout.setBackgroundColor(R.color.black)
        }
        buttonCOOL.setOnClickListener{
            LinearLayout.setBackgroundColor((R.color.teal_200))
        }
    }
}

