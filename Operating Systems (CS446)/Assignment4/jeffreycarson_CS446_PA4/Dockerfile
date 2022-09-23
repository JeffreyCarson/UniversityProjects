# syntax=docker/dockerfile:1

FROM python:latest

WORKDIR /jeffreycarson_CS446_PA4

COPY pythonCode1.py pythonCode1.py

COPY requirements.txt requirements.txt

RUN pip3 install -r requirements.txt

RUN apt-get update
RUN apt-get install ffmpeg libsm6 libxext6  -y

CMD ["python3", "pythonCode1.py"]



