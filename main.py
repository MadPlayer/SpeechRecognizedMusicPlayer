import os
from find_file import choice
import speech_recognition as sr

r = sr.Recognizer()
mic = sr.Microphone()
with mic as source:
    audio = r.listen(source)
    tmp = r.recognize_google(audio, language = "ko-KR")
    print(tmp)
    target = choice.search(tmp)
    print(target)
    os.system('cvlc ' + target + "")
