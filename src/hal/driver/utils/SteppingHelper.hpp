class SteppingHelper
{
public:
    SteppingHelper();

    void setSpeed(const float stepsPerSecond);

    bool step();

    const long getPosition() const;

private:
    long position = 0L;
    float sps = 0.0f;
    unsigned long steppingInterval = 0;
    unsigned long lastStepTime = 0L;
};
