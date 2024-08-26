package com.example.speaksign

import com.google.gson.Gson
import com.google.gson.GsonBuilder
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import retrofit2.http.GET
import retrofit2.http.Headers
import retrofit2.http.Query
import java.util.concurrent.TimeUnit

object RetrofitInstance {
    private const val BASE_URL = "https://american-sign-language-spelling-tool.p.rapidapi.com/"

    private val loggingInterceptor = HttpLoggingInterceptor().apply {
        level = HttpLoggingInterceptor.Level.BODY
    }

    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(loggingInterceptor)
        .connectTimeout(59, TimeUnit.SECONDS)
        .readTimeout(59, TimeUnit.SECONDS)
        .writeTimeout(59, TimeUnit.SECONDS)
        .build()

    private val gson: Gson = GsonBuilder()
        .setLenient()
        .create()

    val api: ASLApi by lazy {
        Retrofit.Builder()
            .baseUrl(BASE_URL)
            .client(okHttpClient)
            .addConverterFactory(GsonConverterFactory.create(gson))
            .build()
            .create(ASLApi::class.java)
    }
}

interface ASLApi {
    @Headers(
        "X-RapidAPI-Key: 9267a5593fmsh6eb1f77693fc970p19f37djsn8228067aefa0",
        "X-RapidAPI-Host: american-sign-language-spelling-tool.p.rapidapi.com"
    )
    @GET("spelling")
    suspend fun getSpelling(
        @Query("text") text: String
    ): retrofit2.Response<SpellingResponse>
}

data class SpellingResponse(
    val data: List<SpellingData>
)

data class SpellingData(
    val letter: String,
    val imageUrl: String
)
