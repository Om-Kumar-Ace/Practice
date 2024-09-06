private fun updateASLImages(text: String) {
        val imageList = mutableListOf<List<StorageReference>>()
        val words = text.split(" ")

        // Step 1: Check for a GIF for the entire sentence
        val sentenceGifRef = storageReference.child("gifs/${text}.gif")
        sentenceGifRef.downloadUrl
            .addOnSuccessListener { uri ->
                // If the sentence GIF exists, load it into the RecyclerView
                imageList.add(listOf(sentenceGifRef))
                aslImageAdapter.updateImageList(imageList)
            }
            .addOnFailureListener {
                // If the sentence GIF doesn't exist, proceed to check groups of words
                checkGroupWordGifs(words, imageList)
            }
    }

    private fun checkGroupWordGifs(
        words: List<String>,
        imageList: MutableList<List<StorageReference>>
    ) {
        val totalGroups = words.size
        var processedGroups = 0

        val maxGroupSize = 3 // Maximum number of words to check as a group
        for (groupSize in maxGroupSize downTo 1) {
            for (i in 0..(words.size - groupSize)) {
                val group = words.subList(i, i + groupSize).joinToString(" ")
                val groupGifRef = storageReference.child("gifs/$group.gif")
                groupGifRef.downloadUrl
                    .addOnSuccessListener { uri ->
                        // If the group GIF exists, load it into the RecyclerView
                        imageList.add(listOf(groupGifRef))
                        processedGroups += groupSize
                        if (processedGroups >= totalGroups) {
                            aslImageAdapter.updateImageList(imageList)
                        }
                    }
                    .addOnFailureListener {
                        // If no GIF is found for this group size, continue
                        if (groupSize == 1) {
                            checkCharacterImages(group, imageList) {
                                processedGroups++
                                if (processedGroups >= totalGroups) {
                                    aslImageAdapter.updateImageList(imageList)
                                }
                            }
                        }
                    }
            }
        }
    }

    private fun checkCharacterImages(
        word: String,
        imageList: MutableList<List<StorageReference>>,
        onComplete: () -> Unit
    ) {
        val charList = mutableListOf<StorageReference?>()
        val totalChars = word.length
        var loadedCount = 0

        word.forEachIndexed { index, char ->
            val fileName = "image/${char.lowercaseChar()}.jpg"
            val imageRef = storageReference.child(fileName)
            imageRef.downloadUrl
                .addOnSuccessListener { uri ->
                    // Store the image reference at the correct position
                    charList.add(index, imageRef)
                    loadedCount++
                    if (loadedCount == totalChars) {
                        imageList.add(charList.filterNotNull())
                        onComplete()
                    }
                }
                .addOnFailureListener { exception ->
                    Toast.makeText(this, "Failed to load image: ${exception.message}", Toast.LENGTH_SHORT).show()
                    Log.e("StorageError", "Error fetching image", exception)
                    loadedCount++
                    if (loadedCount == totalChars) {
                        imageList.add(charList.filterNotNull())
                        onComplete()
                    }
                }
        }
    }