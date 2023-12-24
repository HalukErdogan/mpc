#include <gtest/gtest.h>

#include "mpc/system/continuous_system.hpp"
#include "mpc/integration/stepper/euler_stepper.hpp"

using namespace mpc::system;
using namespace mpc::integration::stepper;

class OneDimCart : public ContinuousSystem<2, 1> {
   public:
    void Dynamics(const State &state, const Control &control,
                   const Time &time, State &result) const override {
        const auto &pos = state(0);
        const auto &vel = state(1);
        const auto &acc = control(0);
        result(0) = vel;
        result(1) = acc;
    }
};

TEST(StepperTest, EulerStepperIntegration) {
    OneDimCart system;
    OneDimCart::State state;
    OneDimCart::Control control;
    OneDimCart::Time time, delta_time;

    state << 0.0, 0.0;
    control << 1.0;
    time = 0.0;
    delta_time = 0.1;

    EulerStepper<OneDimCart> stepper;

    // Perform integration step
    OneDimCart::State result;
    stepper.Step(system, state, control, time, delta_time, result);

    // Check the result against the expected values
    EXPECT_DOUBLE_EQ(result(0), 0.0 + 0.0 * 0.1);  // Position update
    EXPECT_DOUBLE_EQ(result(1), 0.0 + 1.0 * 0.1);  // Velocity update
}