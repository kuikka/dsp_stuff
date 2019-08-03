#include <stdio.h>
#include <fstream>
#include "sinegen.h"
#include "goertzel.h"

int main(int argc, char *argv[])
{
    const float SR = 750000.0f;
    const float F1 = 250000.0f;
    const float F2 = 300000.0f;
    const size_t N = 30;

    Goertzel *bins[N];

    for (auto i = 0; i < N; i++)
    {
        bins[i] = new Goertzel{SR, SR * i / N, N};
    }

    Sinegen gen{F1, SR};
    Sinegen gen2{F2, SR};

    Goertzel go{SR, F1, N};
    Goertzel go2{SR, F2, N};

    std::ofstream outfile ("samples.raw", std::ofstream::binary);

    for (int i = 0; i < N; i++)
    {
        float s = gen.sample();
        float s2 = gen2.sample();

        s = (s + s2) / 2;
//
        for (auto i = 0; i < N; i++)
        {
            bins[i]->process_sample(s);
        }

        go.process_sample(s);
        go2.process_sample(s);

//        printf("%f\n", s);
        outfile.write(reinterpret_cast<const char*>(&s), sizeof(s));
    }

    printf("Goertzel: %f\n", go.get_magnitude_squared());
//    printf("Goertzel: %f\n", go2.get_magnitude_squared());
    for (auto i = 0; i < N; i++)
    {
        printf("G[%u] = %f\n", i, bins[i]->get_magnitude_squared());
    }

    outfile.close();
}
