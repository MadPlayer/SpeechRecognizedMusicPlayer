import os
import sys
from find_file import choice
import speech_recognition as sr

commands = {
        "재생" : "play",
        "일시정지" : "pause",
        "정지" : "stop",
        "종료" : "shutdown"
        }


r = sr.Recognizer()
mic = sr.Microphone()
with mic as source:
    audio = r.listen(source)
    tmp = r.recognize_google(audio, language = "ko-KR")

    if "cmd" in sys.argv :
        ko_cmd = choice.search(tmp, commands)
        print(commands[ko_cmd])
        exit()

    elif "play" in sys.argv :
        file_list = os.listdir()
        audio_list = [val for val in file_list if val.endswith((".wav", ".mp3", ".flac"))]
        #name_list = [name + '.wav', name + '.mp3', name + '.flac']
        music_name = choice.search_list(tmp, audio_list)
        print(music_name)
        os.execv("/usr/bin/cvlc", ["cvlc", music_name])
