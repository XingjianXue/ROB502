import lcm
import time
import numpy as np
from block_goal_msg import block_goal_t

def read_goal(fname):
    transformation = None
    # --- Your code here
    d = np.loadtxt(fname)
    m0 = np.concatenate((d[1:, :].reshape(3, 3), d[0, :].reshape(3, 1)), axis=1)
    transform = np.concatenate((m0.reshape(3, 4), np.array([[0.0, 0.0, 0.0, 1.0]])), axis=0)


     # ---

    return transform

def publish_transform(transform):
    # --- Your code here
    msg.transform = transform
    msg = block_goal_t()   
    msg.timestamp = 0   
    lc.publish('BLOCK_GOAL', msg.encode())
    lc = lcm.LCM()

    # ---

if __name__ == "__main__":
 
    transform = read_goal('inputs1.txt')
    
    while True:
        publish_transform(transform)
        time.sleep(0.1)
