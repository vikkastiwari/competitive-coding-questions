song = "JINGLE Bells jingle Bells Jingle All The Way"
print(song.upper())
song_words = song.split()
count = 0
for word in song_words:
    if(word.startswith("jingle")):
        count += 1
print(count)
