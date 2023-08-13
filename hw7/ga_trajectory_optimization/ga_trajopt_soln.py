import numpy as np
from ga_trajopt import GATrajectoryOptimizer
import math


class GATrajectoryOptimizerSolution(GATrajectoryOptimizer):

    def fitness(self, x):
        fit = 0
        # --- Your code here
        goal = self.goal
        start = np.array([self.start[0], self.start[1]])
        T_lenth = len(x)
        X =np.sum(x, axis=0)+start
        first = math.pow(np.linalg.norm(X-goal), 2)
        

        second = 0
        third = 0
        xt = np.array([self.start[0], self.start[1]])
        for i in range(T_lenth):
            second += math.pow(np.linalg.norm(x[i, ...]), 2)
            xt += x[i, ...]
            Collision = False
            for t in range(len(self.obstacle_radii)):
                if self.obstacle_radii[t] >= math.dist(xt, self.obstacle_centres[t, ...]):
                    Collision = True
            if Collision:
                third = 100 + third
        fit = - third - first - second 


        # ---
        return fit

    def crossover(self, parent1, parent2, crossover_point):
        child1, child2 = None, None
        # --- Your code here

        child1 = np.concatenate((parent1[0:crossover_point, ...], parent2[crossover_point:, ...]), axis=0)
        child2 = np.concatenate((parent2[0:crossover_point, ...], parent1[crossover_point:, ...]), axis=0)


        # ---
        return child1, child2

    def select_children(self, parent, child):

        chosen, fitness = None, None

        # --- Your code here
        p = np.random.rand()
        fitness_p = self.fitness(parent)
        fitness_c = self.fitness(child)
        if fitness_p > fitness_c:
            worse_c = child
            worse_f = fitness_c
            better_c = parent
            better_f = fitness_p

        else:
            better_c = child
            better_f = fitness_c
            worse_c = parent
            worse_f = fitness_p
        
        if p < self.params['select_best_child_p']:
            chosen = better_c
            fitness = better_f
        else:
            chosen = worse_c
            fitness = worse_f


        # ---
        return chosen, fitness


if __name__ == "__main__":
    # GA path planning

    # Setup start, goal and spherical obstacles
    goal = np.array([1.0, 1.0])
    start = np.array([0.0, 0.0])
    obstacle_centres = np.array([
        [0.5, 0.2],
        [0.2, 0.8]
    ])
    obstacle_radii = np.array([0.25, 0.15])

    # Solver parameters
    N = 500
    T = 20
    params = {
        'N': 500,
        'iters': 100,
        'cross_over_p': 0.5,
        'mutate_p': 0.5,
        'select_best_parent_p': 0.9,
        'select_best_child_p': 0.9
    }

    solver = GATrajectoryOptimizerSolution(start, goal, obstacle_radii, obstacle_centres, T, params)
    # Solve to get best trajectory and plot
    best = solver.solve()
    solver.plot_trajectory(best)
