#include <gtest/gtest.h>

#include "mpc/integration/stepper/euler_stepper.hpp"
#include "mpc/system/continuous_system.hpp"

using namespace mpc::system;
using namespace mpc::integration::stepper;

class OneDimCart : public ContinuousSystem {
   public:
    int GetNumState() const { return 2; }
    int GetNumControl() const { return 1; }
    void Dynamics(const Eigen::VectorXd &state, const Eigen::VectorXd &control,
                  const double &time, Eigen::VectorXd &result) const override {
        const auto &pos = state(0);
        const auto &vel = state(1);
        const auto &acc = control(0);
        result(0) = vel;
        result(1) = acc;
    }
};

TEST(StepperTest, EulerStepperIntegration) {
    OneDimCart system;
    Eigen::VectorXd state;
    Eigen::VectorXd control;
    double time, delta_time;

    state << 0.0, 0.0;
    control << 1.0;
    time = 0.0;
    delta_time = 0.1;

    EulerStepper stepper;

    // Perform integration step
    Eigen::VectorXd result;
    stepper.Step(system, state, control, time, delta_time, result);

    // Check the result against the expected values
    EXPECT_DOUBLE_EQ(result(0), 0.0 + 0.0 * 0.1);  // Position update
    EXPECT_DOUBLE_EQ(result(1), 0.0 + 1.0 * 0.1);  // Velocity update
}