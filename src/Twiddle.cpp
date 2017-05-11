#include "Twiddle.h"
#include <iostream>
#include <limits>

using namespace std;

Twiddle::Twiddle()
{
  best_err_ = std::numeric_limits<double>::max();
}

Twiddle::~Twiddle() {}

void Twiddle::init(double Kp, double Ki, double Kd)
{
  p_[0] = Kp;
  p_[1] = Ki;
  p_[2] = Kd;
  count = 0;
}


bool Twiddle::record(double cte)
{
  err_ += cte * cte;
  ++count;

  return count < 1500 && err_ < best_err_;
}

void Twiddle::update()
{
  err_ = err_ / count * 1500;
  if (status)
  {
    if (err_ < best_err_)
    {
      best_err_ = err_;
      best_p_[0] = p_[0];
      best_p_[1] = p_[1];
      best_p_[2] = p_[2];
      dp_[index] *= 1.1;
    }
    else
    {
      p_[index] += dp_[index];
      dp_[index] *= 0.9;
    }
    status = false;
  }
  else
  {
    if (err_ < best_err_)
    {
      best_err_ = err_;
      best_p_[0] = p_[0];
      best_p_[1] = p_[1];
      best_p_[2] = p_[2];
      dp_[index] *= 1.1;
    }
    else
    {
      p_[index] -= 2 * dp_[index];
      status = true;
    }
  }

  if (!status)
  {
    index = (++index) % 3;
    // if (index == 1)
    //   index = 2;
    p_[index] += dp_[index];
    cout << endl << endl << endl;
    cout << index << " " << p_[0] << " " << p_[1] << " " << p_[2] << endl;
    cout << "  " << dp_[0] << " " << dp_[1] << " " << dp_[2] << endl;
    cout << endl << endl;
  }

  count = 0;
  err_ = 0.0;
}

double* Twiddle::getP()
{
  return p_;
}

double Twiddle::sumOfDp()
{
  return dp_[0] + dp_[1] + dp_[2];
}
