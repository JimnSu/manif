#ifndef _MANIF_MANIF_TEST_COMMON_TESTER_H_
#define _MANIF_MANIF_TEST_COMMON_TESTER_H_

#include "test_utils.h"
#include "manif/algorithms/interpolation.h"
#include "manif/algorithms/average.h"

#define MANIF_TEST(manifold)                                              \
  using TEST_##manifold##_TESTER = CommonTester<manifold>;                \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_COPY_CONSTRUCTOR)    \
  { evalCopyConstructor(); }                                              \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_ASSIGNMENT)          \
  { evalAssignment(); }                                                   \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_DATA_PTR_VALID)      \
  { evalDataPtrValid(); }                                                 \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_PLUS_IS_RPLUS)       \
  { evalPlusIsRplus(); }                                                  \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_PLUS_OP_IS_RPLUS)    \
  { evalPlusOpIsRplus(); }                                                \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_MINUS_IS_RMINUS)     \
  { evalMinusIsRminus(); }                                                \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_MINUS_OP_IS_RMINUS)  \
  { evalMinusOpIsRminus(); }                                              \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_PLUS_EQ)             \
  { evalPlusEq(); }                                                       \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_COMPOSE_OP)          \
  { evalCompOp(); }                                                       \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_COMPOSE_EQ_OP)       \
  { evalCompEq(); }                                                       \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_LIFT_RETRACT)        \
  { evalLiftRetr(); }                                                     \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_RETRACT_LIFT)        \
  { evalLiftRetr(); }                                                     \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_COMPOSE_WITH_INV)    \
  { evalComposeWithInv(); }                                               \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_BETWEEN_SELF)        \
  { evalBetweenSelf(); }                                                  \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_PLUS_ZERO)           \
  { evalPlusZero(); }                                                     \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_MINUS_SELF)          \
  { evalMinusSelf(); }                                                    \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_RETRACT_ZERO)        \
  { evalRetrZero(); }                                                     \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_LIFT_IDENTITY)       \
  { evalLiftIdentity(); }                                                 \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_RANDOM)              \
  { evalRandom(); }                                                       \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_ZERO)                \
  { evalZero(); }                                                         \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_SLERP10)             \
  { evalSlerp01(); }                                                      \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_AVG_BIINVARIANT)     \
  { evalAvgBiInvariant(); }                                               \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_IS_APPROX)           \
  { evalIsApprox(); }                                                     \
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_UNARY_MINUS)         \
  { evalUnaryMinus(); }

/*
  TEST_F(TEST_##manifold##_TESTER, TEST_##manifold##_CUBIC10)             \
  { evalCubic01(); }                                                      \
*/

#define MANIF_TEST_JACOBIANS(manifold)                                            \
  using TEST_##manifold##_JACOBIANS_TESTER = JacobianTester<manifold>;            \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_INVERSE_JACOBIANS) \
  { evalInverseJac(); }                                                           \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_LIFT_JACOBIANS)    \
  { evalLiftJac(); }                                                              \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_RETRACT_JACOBIANS) \
  { evalRetractJac(); }                                                           \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_RPLUS_JACOBIANS)   \
  { evalRplusJac(); }                                                             \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_LPLUS_JACOBIANS)   \
  { evalLplusJac(); }                                                             \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_PLUS_JACOBIANS)    \
  { evalPlusJac(); }                                                              \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_RMINUS_JACOBIANS)  \
  { evalRminusJac(); }                                                            \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_LMINUS_JACOBIANS)  \
  { evalLminusJac(); }                                                            \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_MINUS_JACOBIANS)   \
  { evalMinusJac(); }                                                             \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_COMPOSE_JACOBIANS) \
  { evalComposeJac(); }                                                           \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_BETWEEN_JACOBIANS) \
  { evalBetweenJac(); }                                                           \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_ADJ)               \
  { evalAdj(); }                                                                  \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_ADJ_JL_JR)         \
  { evalAdjJlJr(); }                                                              \
  TEST_F(TEST_##manifold##_JACOBIANS_TESTER, TEST_##manifold##_JLJLinv_JRJRinv)   \
  { evalJrJrinvJlJlinv(); }

namespace manif {

/**
 * @brief A helper class to test some common functionalities
 */
template <typename _LieGroup>
class CommonTester : public ::testing::Test
{
  using LieGroup = _LieGroup;
  using Scalar   = typename LieGroup::Scalar;
  using Tangent  = typename LieGroup::Tangent;

public:

  CommonTester()  = default;
  ~CommonTester() = default;

  void SetUp() override
  {
    std::srand((unsigned int) time(0));

    state       = LieGroup::Random();
    state_other = LieGroup::Random();

    delta = Tangent::Random();
  }

  void evalCopyConstructor()
  {
    LieGroup state_copy(state);
    EXPECT_MANIF_NEAR(state, state_copy, tol_);
  }

  void evalAssignment()
  {
    LieGroup state_copy;
    state_copy = state;
    EXPECT_MANIF_NEAR(state, state_copy, tol_);
  }

  void evalDataPtrValid()
  {
    ASSERT_NE(nullptr, state.data());
  }

  void evalPlusIsRplus()
  {
    EXPECT_MANIF_NEAR(state.rplus(delta),
                      state.plus(delta), tol_);
  }

  void evalPlusOpIsRplus()
  {
    EXPECT_MANIF_NEAR(state.rplus(delta),
                      state + delta, tol_);
  }

  void evalMinusIsRminus()
  {
    EXPECT_MANIF_NEAR(state.rminus(state_other),
                      state.minus(state_other), tol_);
  }

  void evalMinusOpIsRminus()
  {
    EXPECT_MANIF_NEAR(state.rminus(state_other),
                      state - state_other, tol_);
  }

  void evalPlusEq()
  {
    LieGroup ret = state;
    ret += delta;

    EXPECT_MANIF_NEAR(state + delta, ret, tol_);
  }

  void evalCompOp()
  {
    EXPECT_MANIF_NEAR(state.compose(state_other),
                      state * state_other, tol_);
  }

  void evalCompEq()
  {
    LieGroup ret = state;
    ret *= state_other;

    EXPECT_MANIF_NEAR(state * state_other, ret, tol_);
  }

  void evalLiftRetr()
  {
    EXPECT_MANIF_NEAR(state, state.lift().retract(), tol_);
  }

  void evalRetrLift()
  {
    EXPECT_MANIF_NEAR(delta, delta.retract().lift(), tol_);
  }

  void evalComposeWithInv()
  {
    EXPECT_MANIF_NEAR(LieGroup::Identity(),
                      state.compose(state.inverse()), tol_);
    EXPECT_MANIF_NEAR(LieGroup::Identity(),
                      state * state.inverse(), tol_);

    LieGroup tmp = state; tmp *= state.inverse();
    EXPECT_MANIF_NEAR(LieGroup::Identity(), tmp, tol_);

    EXPECT_MANIF_NEAR(state, state * LieGroup::Identity(), tol_);
    EXPECT_MANIF_NEAR(state, LieGroup::Identity() * state, tol_);
  }

  void evalBetweenSelf()
  {
    EXPECT_MANIF_NEAR(LieGroup::Identity(),
                      state.between(state), tol_);
  }

  void evalPlusZero()
  {
    EXPECT_MANIF_NEAR(LieGroup::Identity(),
                      LieGroup::Identity() + Tangent::Zero(), tol_);
    EXPECT_MANIF_NEAR(state,
                      state + Tangent::Zero(), tol_);
  }

  void evalMinusSelf()
  {
    EXPECT_MANIF_NEAR(Tangent::Zero(),
                      LieGroup::Identity() - LieGroup::Identity(), tol_);
    EXPECT_MANIF_NEAR(Tangent::Zero(),
                      state - state, tol_);
  }

  void evalRetrZero()
  {
    EXPECT_MANIF_NEAR(LieGroup::Identity(),
                      Tangent::Zero().retract(), tol_);
  }

  void evalLiftIdentity()
  {
    EXPECT_MANIF_NEAR(Tangent::Zero(),
                      LieGroup::Identity().lift(), tol_);

    Tangent t; t.setZero();
    LieGroup l; l.setIdentity();
    EXPECT_MANIF_NEAR(t, l.lift(), tol_);
  }

  void evalRandom()
  {
    // seed is init thus random should be different
    EXPECT_MANIF_NOT_NEAR(Tangent::Random(),
                          Tangent::Random(), tol_);

    EXPECT_MANIF_NOT_NEAR(Tangent().setRandom(),
                          Tangent().setRandom(), tol_);
  }

  void evalZero()
  {
    EXPECT_EIGEN_NEAR(Tangent::Zero().coeffs(),
                      Tangent::DataType::Zero());
  }

  void evalSlerp01()
  {
    LieGroup interp = interpolate(state, state_other, 0);

    EXPECT_MANIF_NEAR(state, interp, tol_);

    interp = interpolate(state, state_other, 1);

    EXPECT_MANIF_NEAR(state_other, interp, tol_);
  }

  void evalCubic01()
  {
    LieGroup interp = interpolate(state, state_other, 0, INTERP_METHOD::CUBIC);

    EXPECT_MANIF_NEAR(state, interp, tol_);

    interp = interpolate(state, state_other, 1, INTERP_METHOD::CUBIC);

    EXPECT_MANIF_NEAR(state_other, interp, tol_);
  }

  void evalAvgBiInvariant()
  {
    const auto dummy = LieGroup::Random();
    EXPECT_MANIF_NEAR(dummy,
     average_biinvariant(std::vector<LieGroup>{dummy}), tol_);

    std::vector<LieGroup> mans;

    const int N = 15;
    for (int i=0; i<N; ++i)
      mans.emplace_back(LieGroup::Random());

    const auto avg = average_biinvariant(mans);

    // A proper mean function should always return
    // the same mean no matter the initial pivot.
    for (int i=0; i<20; ++i)
    {
      std::random_shuffle( mans.begin(), mans.end() );

      const auto avg_shu = average_biinvariant(mans);

      EXPECT_MANIF_NEAR(avg, avg_shu, 1e-8);
    }
  }

  void evalIsApprox()
  {
    EXPECT_TRUE(state.isApprox(state, tol_));
    EXPECT_FALSE(state.isApprox(state_other, tol_));

    EXPECT_TRUE(state == state);
    EXPECT_FALSE(state == state_other);
  }

  void evalUnaryMinus()
  {
    Tangent minus_delta = -delta;
    typename Tangent::DataType delta_data = delta.coeffs();
    typename Tangent::DataType minus_delta_data = minus_delta.coeffs();
    EXPECT_EIGEN_NEAR(-delta_data, minus_delta_data);
    EXPECT_EIGEN_NEAR(-delta.coeffs(), minus_delta.coeffs());
  }

protected:

  Scalar tol_ = Constants<Scalar>::eps;

  LieGroup state;
  LieGroup state_other;
  Tangent  delta;
};

/**
 * @brief A helper class to test general Jacobians
 *
 * assert_near(f(R.plus(w)) , f(R).plus(J_f_R * w)
 * assert_near(f(R.plus(w)) , f(R) + (J_f_R * w)
 *
 * GENERAL JACOBIANS
 *
 * Assert is through linearized equation
 * J = df/dR ==> f( R(+)w ) ~= f(R) (+) J*w, where (+) is right-plus
 *
 * The Jacobians of the following operations are currently tested :
 *
 * - inverse
 * - lift
 * - retract
 * - compose
 * - between
 * - rplus  / lplus  / plus
 * - rminus / lminus / minus
 *
 */
template <typename _LieGroup>
class JacobianTester : public ::testing::Test
{
  using LieGroup = _LieGroup;
  using Tangent  = typename _LieGroup::Tangent;

public:

  JacobianTester()  = default;
  ~JacobianTester() = default;

  void SetUp() override
  {
    std::srand((unsigned int) time(0));

    state       = LieGroup::Random();
    state_other = LieGroup::Random();

    delta = Tangent::Random();
    w     = Tangent(Tangent::DataType::Random()*w_order_);
  }

  void evalInverseJac()
  {
    typename LieGroup::Jacobian J_sout_s;
    LieGroup state_out = state.inverse(J_sout_s);

    LieGroup state_pert = (state+w).inverse();
    LieGroup state_lin  = state_out.rplus(J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalLiftJac()
  {
    typename LieGroup::Jacobian J_sout_s;
    Tangent state_out = state.lift(J_sout_s);

    Tangent state_pert = (state+w).lift();
    Tangent state_lin  = state_out + (J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalRetractJac()
  {
    typename LieGroup::Jacobian J_sout_s;
    LieGroup state_out = delta.retract(J_sout_s);

    LieGroup state_pert = (delta+w).retract();
    LieGroup state_lin  = state_out + (J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalComposeJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_sout_so;
    LieGroup state_out = state.compose(state_other, J_sout_s, J_sout_so);

    // Jac wrt first element

    LieGroup state_pert = (state+w).compose(state_other);
    LieGroup state_lin  = state_out + J_sout_s*w;

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.compose(state_other+w);
    state_lin  = state_out + J_sout_so*w;

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalBetweenJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_sout_so;
    LieGroup state_out = state.between(state_other, J_sout_s, J_sout_so);

    // Jac wrt first element

    LieGroup state_pert = (state + w).between(state_other);
    LieGroup state_lin  = state_out + (J_sout_s * w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.between(state_other + w);
    state_lin  = state_out + (J_sout_so * w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalRplusJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_sout_t;
    LieGroup state_out = state.rplus(delta, J_sout_s, J_sout_t);

    // Jac wrt first element

    LieGroup state_pert = (state+w).rplus(delta);
    LieGroup state_lin  = state_out.rplus(J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.rplus(delta+w);
    state_lin  = state_out.rplus(J_sout_t*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalLplusJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_sout_t;
    LieGroup state_out = state.lplus(delta, J_sout_s, J_sout_t);

    // Jac wrt first element

    LieGroup state_pert = (state+w).lplus(delta);
    LieGroup state_lin  = state_out.rplus(J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.lplus(delta+w);
    state_lin  = state_out.rplus(J_sout_t*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalPlusJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_mout_t;
    LieGroup state_out = state.plus(delta, J_sout_s, J_mout_t);

    // Jac wrt first element

    LieGroup state_pert = (state+w).plus(delta);
    LieGroup state_lin  = state_out.rplus(J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.plus(delta+w);
    state_lin  = state_out.rplus(J_mout_t*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalRminusJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_mout_so;
    Tangent state_out = state.rminus(state_other, J_sout_s, J_mout_so);

    // Jac wrt first element

    Tangent state_pert = (state+w).rminus(state_other);
    Tangent state_lin  = state_out.plus(J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.rminus(state_other+w);
    state_lin  = state_out.plus(J_mout_so*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalLminusJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_mout_so;
    Tangent state_out = state.lminus(state_other, J_sout_s, J_mout_so);

    // Jac wrt first element

    Tangent state_pert = (state+w).lminus(state_other);
    Tangent state_lin  = state_out.plus(J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.lminus(state_other+w);
    state_lin  = state_out.plus(J_mout_so*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalMinusJac()
  {
    typename LieGroup::Jacobian J_sout_s, J_mout_so;
    Tangent state_out = state.minus(state_other, J_sout_s, J_mout_so);

    // Jac wrt first element

    Tangent state_pert = (state+w).minus(state_other);
    Tangent state_lin  = state_out.plus(J_sout_s*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);

    // Jac wrt second element

    state_pert = state.minus(state_other+w);
    state_lin  = state_out.plus(J_mout_so*w);

    EXPECT_MANIF_NEAR(state_pert, state_lin, tol_);
  }

  void evalAdj()
  {
    typename LieGroup::Jacobian Adja, Adjb, Adjc;

    Adja = state.adj();
    Adjb = state_other.adj();
    Adjc = state.compose(state_other).adj();

    EXPECT_EIGEN_NEAR(Adja*Adjb, Adjc);

    //EXPECT_MANIF_NEAR(state.adj()*delta, (state*delta*state.inverse()).vee());
    EXPECT_MANIF_NEAR(state+delta, state.adj()*delta+state);
    EXPECT_EIGEN_NEAR(state.adj().inverse(), state.inverse().adj());
  }

  void evalAdjJlJr()
  {
    typename LieGroup::Jacobian Adj, Jr, Jl;

    Adj = state.adj();

    const Tangent tan = state.lift();

    Jr = tan.rjac();
    Jl = tan.ljac();

    EXPECT_EIGEN_NEAR(Jl, Adj*Jr);
    EXPECT_EIGEN_NEAR(Adj, Jl*Jr.inverse());

    // Jr(-tau) = Jl(tau)

    typename LieGroup::Jacobian Jr_mtau = (-tan).rjac();
    EXPECT_EIGEN_NEAR(Jl, Jr_mtau);
  }

  void evalJrJrinvJlJlinv()
  {
    using Jac = typename LieGroup::Jacobian;
    Jac Jr, Jrinv, Jl, Jlinv;

    const Tangent tan = state.lift();

    Jr = tan.rjac();
    Jl = tan.ljac();

    Jrinv = tan.rjacinv();
    Jlinv = tan.ljacinv();

    EXPECT_EIGEN_NEAR(Jac::Identity(), Jr*Jrinv);
    EXPECT_EIGEN_NEAR(Jac::Identity(), Jl*Jlinv);
  }

  void setOmegaOrder(const double w_order) { w_order_ = w_order; }
  void setTolerance(const double tol) { tol_ = tol; }

  double getOmegaOrder() const noexcept { return w_order_; }
  double getTolerance() const noexcept { return tol_; }

protected:

  double w_order_ = 1e-4;
  double tol_ = 1e-8;

  LieGroup state;
  LieGroup state_other;
  Tangent  delta;
  Tangent  w; //
};

} /* namespace manif */

#endif /* _MANIF_MANIF_TEST_COMMON_TESTER_H_ */