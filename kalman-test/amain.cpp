/*
 * \file amain.cpp
 * \brief 
 *
 * \author C.T. Chadwick: Monadnock Capital Management, LP
 * \date 2019-09
 */
// -------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <Eigen/Dense>

#include <fmt/format.h>

class KalmanFilter 
{
public:
	/**
	* Create a Kalman filter with the specified matrices.
	*   A - System dynamics matrix
	*   C - Output matrix
	*   Q - Process noise covariance
	*   R - Measurement noise covariance
	*   P - Estimate error covariance
	*   https://github.com/hmartiro/kalman-cpp/blob/master/kalman-test.cpp
	*/
	KalmanFilter() : mA(2,2), mC(1,2), mQ(2,2), mR(1,1), mI(2,2), x_hat(2), x_hat_new(2)
	{
		mI.setIdentity();
		mA << 1, 0, 0, 1;
		mC << 1, 0;
		mQ << 0.05, 0.05, 0.05, 0.05;
		mR << 1;
		mP << 0.0, 0.0, 0.0, 0.0;
	}
   
	void init(const Eigen::VectorXd& x0)
	{
		x_hat = x0;
	}
	
	void update(const Eigen::VectorXd& y)
	{
		x_hat_new = mA * x_hat;
		mP = mA * mP * mA.transpose() + mQ;
		mK = mP * mC.transpose() * (mC * mP * mC.transpose() + mR).inverse();
		x_hat_new += mK * (y - mC * x_hat_new);
		mP = (mI - mK * mC)* mP;
		x_hat = x_hat_new;
	}
	
	double value() 
	{ 
		return x_hat.transpose().data()[0]; 
	}

private:
	Eigen::MatrixXd mA, mC, mQ, mR, mP, mK;
	Eigen::MatrixXd mI;
	Eigen::VectorXd x_hat, x_hat_new;
};


// -------------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) 
{
  // Construct the filter
  KalmanFilter kf;

  // List of noisy position measurements (y)
  std::vector<double> measurements = {
      67.427,67.3985,67.3955,67.397667,67.3815,67.3685,67.3995,67.422286,67.406,67.399,67.417667,67.4526,67.4438,67.4285,67.4675,67.4719,67.473167,67.447429,67.431556,67.42075,67.401364,67.400769,67.461143,67.49375,67.524,67.525667,67.521,67.494,67.4793,67.460125,67.470077,67.5165,67.497833,67.486,67.50225,67.502167,67.483667,67.519714,67.5037,67.495286,67.551,67.547333,67.586,67.602,67.611,67.601,67.5754,67.623,67.61875,67.600667,67.6186,67.616333,67.614,67.6345,67.665333,67.662,67.6394,67.6342,67.616667,67.6195,67.6182,67.6278,67.606,67.572667,67.562857,67.5255,67.492,67.489,67.484,67.5025,67.512,67.5468,67.5466,67.542125,67.590333,67.566111,67.525625,67.530286,67.523889,67.5045,67.4862,67.4885,67.509857,67.501909,67.478889,67.486444,67.4606,67.4555,67.473143,67.432857,67.418667,67.411333,67.42725,67.4194,67.38,67.3635,67.326,67.323,67.304,67.297,67.288,67.293,67.2915,67.276,67.253,67.262,67.26775,67.265,67.28375,67.2776,67.298,67.317,67.308,67.307375,67.290333,67.288889,67.336,67.3715,67.3765,67.3545,67.373429,67.394,67.406,67.398,67.406,67.421143,67.446,67.45575,67.4185,67.405,67.3895,67.3692,67.3535,67.34475,67.338,67.350375,67.311143,67.295667,67.300714,67.336333,67.368286,67.3664,67.333,67.297333,67.251,67.235,67.251,67.2625,67.283,67.274571,67.30725,67.323833,67.340714,67.345,67.3872,67.405333,67.4058,67.4095,67.43,67.44625,67.43325,67.43125,67.472,67.512,67.534,67.54,67.527,67.4975,67.4795,67.4595,67.425,67.4458,67.4615,67.4748,67.499,67.490833,67.484375,67.492667,67.46525,67.4525,67.46475,67.464111,67.482,67.498333,67.487667,67.4998,67.532,67.5086,67.490273,67.478167,67.483571,67.464,67.442,67.458,67.4795,67.474615,67.483,67.468231,67.4435,67.4822,67.482833,67.4055,67.3885,67.38,67.347,67.33,67.333,67.3556,67.357,67.385125,67.410154,67.458333,67.46025,67.44725,67.436429,67.421091,67.4416,67.461222,67.489333,67.477,67.4972,67.48925,67.49425,67.486455,67.4974,67.5275,67.535833,67.597,67.591,67.5915,67.581,67.583857,67.627,67.641,67.643,67.647,67.634,67.630857,67.600375,67.592,67.592111,67.572833,67.580857,67.6115,67.63325,67.620125,67.668,67.713,67.701,67.696,67.68375,67.682333,67.6615,67.641,67.627,67.636857,67.6822,67.719,67.706667,67.689625,67.648,67.669667,67.652333,67.656857,67.6654,67.63975,67.62825,67.6165,67.604,67.63925,67.6355,67.629,67.645,67.626571,67.613875,67.621857,67.640286,67.637833,67.654667,67.66875,67.686833,67.694,67.741,67.778,67.774,67.774,67.757,67.75625,67.74025,67.749833,67.75125,67.779833,67.771,67.795,67.800667,67.8285,67.81375,67.8186,67.791667,67.764286,67.759,67.765125,67.739333,67.701,67.69525,67.704615,67.695833,67.719429,67.720556,67.742778,67.778714,67.8015,67.779875,67.749143,67.744091,67.735923,67.714875,67.716625,67.7375,67.765,67.782125,67.815857,67.844,67.8765,67.871,67.84675,67.856429,67.845875,67.8685,67.8664,67.842857,67.8262,67.854571,67.876556,67.882154,67.838714,67.8491,67.862667,67.874667,67.91,67.897875,67.883,67.8694,67.909333,67.902167,67.889,67.902143,67.899,67.896778,67.887,67.882,67.888778,67.88525,67.885,67.86225,67.83625,67.860556,67.894,67.916667,67.9338,67.9109,67.9117,67.8816,67.85875,67.847455,67.8272,67.8295,67.849667,67.822167,67.7685,67.762,67.762333,67.767833,67.738667,67.71,67.718,67.7115,67.725083,67.733308,67.731889,67.7721,67.79875,67.798,67.8168,67.84525,67.8332,67.834625,67.846,67.851769,67.87075,67.9005,67.910769,67.921833,67.923167,67.926455,67.95475,67.997,68.004,68.021,68.038,68.054,68.0525,68.037333,68.0315,68.018143,67.9974,67.972,67.9785,67.960667,67.954,67.957364,67.9613,67.9763,67.963444,67.9629,67.95725,67.949882,67.942167,67.986667,68.0022,68.057,68.05,68.0505,68.071,68.0825,68.06,68.046,68.0428,68.010308,68.013571,68.029071,68.041625,68.046231,68.047091,68.059571,68.0845,68.09,68.089667,68.0892,68.121,68.098,68.0965,68.132667,68.122333,68.121857,68.107,68.10025,68.13225,68.120333,68.1325,68.140571,68.147,68.137889,68.1465,68.140071,68.149167,68.16375,68.1348,68.093,68.092429,68.095143,68.083867,68.084,68.12,68.150429,68.175167,68.1727,68.18,68.193,68.174857,68.194556,68.247,68.244,68.251,68.238,68.218667,68.2056,68.223375,68.2378,68.2485,68.27725,68.358,68.354,68.378,68.37,68.378,68.373,68.371,68.373,68.372,68.374,68.363,68.353,68.349,68.344,68.353667,68.3675,68.381,68.415,68.402,68.395429,68.38825,68.364,68.352,68.3335,68.305,68.269,68.251,68.232,68.256,68.2725,68.262,68.287167,68.294267,68.2795,68.266889,68.309333,68.322333,68.3218,68.33425,68.366,68.361,68.365444,68.35625,68.424,68.438,68.4495,68.473,68.4495,68.429,68.434857,68.4845,68.508,68.492,68.484,68.4805,68.4515,68.4575,68.4475,68.474833,68.492,68.501667,68.513,68.495,68.5155,68.553,68.574,68.58,68.583,68.5605,68.5205,68.493,68.497333,68.5,68.4985,68.4906,68.489143,68.482,68.481714,68.489727,68.5195,68.537143,68.510429,68.5215,68.490222,68.473667,68.447,68.443,68.453714,68.443429,68.4735,68.479286,68.432,68.471,68.4895,68.45725,68.438188,68.426778,68.44,68.444571,68.456462,68.450429,68.478111,68.45975,68.4434,68.461563,68.4788,68.485125,68.50325,68.527,68.5063,68.525714,68.5415,68.561667,68.55625,68.5675,68.560083,68.55,68.557,68.5474,68.5264,68.464,68.465143,68.423,68.41675,68.411667,68.4405,68.443538,68.4366,68.404333,68.381,68.366667,68.326,68.303,68.2745,68.287,68.296,68.312333,68.314714,68.338143,68.341,68.29575,68.284,68.2175,68.188,68.175,68.19,68.1855,68.1845,68.1798,68.19575,68.181091,68.181667,68.176375,68.1658,68.149,68.167333,68.199,68.235,68.1985,68.21125,68.256,68.27525,68.2985,68.2915,68.263,68.278333,68.361,68.36125,68.360333,68.395,68.393,68.404,68.426,68.4395,68.4485,68.443,68.429,68.428,68.438,68.4415,68.456,68.443,68.431,68.423,68.436,68.453,68.464,68.4725,68.4632,68.474,68.506667,68.495455,68.486545,68.4924,68.484437,68.496357,68.543286,68.534053,68.5296,68.524167,68.510611,68.512667,68.504579,68.486353,68.4678,68.456545,68.462167,68.475981,68.483406,68.462235,68.443526
  };

  // Best guess of initial states
  Eigen::VectorXd x0(2);
  x0 << measurements[0], measurements[1];
  kf.init(x0);

  // Feed measurements into filter, output estimated states
  Eigen::VectorXd y(1);
  for(int i = 0; i < measurements.size(); i++) 
  {
    y << measurements[i];
    kf.update(y);
	std::cout << fmt::format("i[{:03d}] m[{:f}] xh[{:f}]", i, measurements[i], kf.value()) << std::endl;
  }

  return 0;
}

