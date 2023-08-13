import numpy as np


def estimate_pi(N):
    pi_estimate = None
    # --- Your code here
    Ncircle = 0
    for num in range(N):
        x = np.random.rand()-0.5
        y = np.random.rand()-0.5
        if x*x + y*y <= 0.25:
            Ncircle = Ncircle + 1
    
    pi_estimate = 4*Ncircle/N
    
    # ---

    return pi_estimate


if __name__ == "__main__":
    N = 1000
    approx_pi = estimate_pi(N)
    print(f'Estimate of pi is {approx_pi}')