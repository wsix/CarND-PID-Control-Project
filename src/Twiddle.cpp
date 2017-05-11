#include "Twiddle.h"
#include <iostream>
#include <limits>

Twiddle::Twiddle(double tol)
{
  tol_ = tol;
  best_err_ = std::numeric_limits<double>::max();
}

Twiddle::~Twiddle() {}

bool Twiddle::record(double cte)
{
  err_ += cte * cte;
  ++count;

  return count < 1000 && err_ < best_err_;
}

void Twiddle::update()
{
  if (status)
  {
    if (err_ < best_err_)
    {
      best_err_ = err_;
      best_p_[index] = p_[index];
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
      best_p_[index] = p_[index];
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
    p_[index] += dp_[index];
    count = 0;
    err_ = 0.0;
  }
}

double* Twiddle::getBestP()
{
  return best_p_;
}
