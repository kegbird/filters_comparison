﻿#ifndef UTILS
#define UTILS

#define CHECK(call)                                                            \
{                                                                              \
    const cudaError_t error = call;                                            \
    if (error != cudaSuccess)                                                  \
    {                                                                          \
        fprintf(stderr, "Error: %s:%d, ", __FILE__, __LINE__);                 \
        fprintf(stderr, "code: %d, reason: %s\n", error,                       \
                cudaGetErrorString(error));                                    \
    }                                                                          \
}

bool check_input(char* filename);
void print_file_details(char* filename);
unsigned char* load_file_details(char* filename, int* width, int* height, int* channels, size_t* image_size, size_t* filtered_image_size, int* f_width, int* f_height, int kernel_radius);
void begin_timer();
void end_timer();
float time_elapsed();
void set_cpu_time(float time);
float speedup();
void save_file(char* filename, unsigned char* image, int width, int height, int channels);

#endif