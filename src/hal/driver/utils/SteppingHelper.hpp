class SteppingHelper
{
public:
    SteppingHelper();

    void setSpeed(float stepsPerSecond);

    bool step();

    long getPosition() const;

private:
    long mPosition = 0L;
    float mSps = 0.0f;
    unsigned long mSteppingInterval = 0;
    unsigned long mLastStepTime = 0L;
};
