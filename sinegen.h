#pragma once
#include <math.h>

class Sinegen
{
public:
    Sinegen(float f, float sr, float phase = 0.0f)
        : m_f(f)
        , m_counter(phase)
        , m_step(f * 2 * M_PI / sr)
    {}

    float sample()
    {
        const float s = sinf(m_counter);
        m_counter += m_step;
        return s;
    }

private:
    float m_f;
    float m_counter;
    float m_step;
};
