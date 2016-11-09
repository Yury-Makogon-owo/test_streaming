#include <jni.h>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <stdio.h>
#include <string>

extern "C"
jstring
Java_test_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    char buffer[128];
    const char* cmd = "ls";
    std::string result = "Hello we did it";
    /*FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        //throw;
    }
    pclose(pipe);*/

    //system("screenrecord --output-format h264 - | /data/ffmpeg -f h264 -i - -vcodec copy -f mpegts udp://172.31.149.40:1234 &");
    //system("/data/ffmpeg -f h264 -i /data/movie.mp4 -vcodec copy -f mpegts udp://172.31.149.40:1234 &");
    system("/data/ffmpeg -re -i /data/movie.mp4 -codec:v copy -an -bsf:v h264_mp4toannexb,dump_extra -f mpegts udp://172.31.149.40:1234 &");
    return env->NewStringUTF(result.c_str());
}

