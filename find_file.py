import os
import difflib

class choice:
    def __init__(self):
        self.ratio = 0
        self.name = ''

    def refresh(self, ratio, name):
        if self.ratio < ratio:
            self.ratio = ratio
            self.name = name

    def get(self):
        ans = ''
        l = len(self.name)
        for i in range(l - 1):
            ans += (self.name[i] + '\ ')

        ans += self.name[l - 1]
        return ans

    #get the string input and play the song
    def search(name = ''):
        file_list = os.listdir()
        audio_list = [val for val in file_list if val.endswith((".wav", ".mp3", ".flac"))]
        name_list = [name + '.wav', name + '.mp3', name + '.flac']

        music = choice()
        for n in name_list:
            for audio in audio_list:
                seq = difflib.SequenceMatcher(None, n, audio)
                music.refresh(seq.ratio(), audio)

        return music.get()
