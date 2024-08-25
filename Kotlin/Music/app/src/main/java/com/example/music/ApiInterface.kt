package com.example.music

import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Header
import retrofit2.http.Headers
import retrofit2.http.Query


interface ApiInterface {
    @Headers("x-rapidapi-key :9267a5593fmsh6eb1f77693fc970p19f37djsn8228067aefa0",
        "x-rapidapi-host :deezerdevs-deezer.p.rapidapi.com")
    @GET("search")
    fun getData(@Query("q") query: String): Call<Mydata>

}