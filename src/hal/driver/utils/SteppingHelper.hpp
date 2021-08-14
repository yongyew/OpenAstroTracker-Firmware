class SteppingHelper
{
public:
    SteppingHelper();

    void setSpeed(float stepsPerSecond);

    bool step();

    long getPosition() const;

private:
    long _position = 0L;
    float _sps = 0.0f;
    unsigned long _steppingInterval = 0;
    unsigned long _lastStepTime = 0L;
};
