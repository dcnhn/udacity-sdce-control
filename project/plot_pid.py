import pandas as pd
import matplotlib.pyplot as plt

def read_steer_data():
 steer_file = 'steer_pid_data.txt'
 steer_df = pd.read_csv(steer_file, delim_whitespace = True, header = None, usecols = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
 steer_df.columns = ['Iteration', 'Sim Time', 'Error Steering', 'Steering Output', 'Yaw', 'Planned Yaw', 'x Current', 'y Current', 'x Target', 'y Target', 'Output-P', 'Output-I', 'Output-D']
 print(f'Steer data:\n{steer_df.head()}\n')
 return steer_df


def read_throttle_data():
 throttle_file = 'throttle_pid_data.txt'
 throttle_df = pd.read_csv(throttle_file, delim_whitespace = True, header = None, usecols = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 throttle_df.columns = ['Iteration', 'Sim Time', 'Error Speed', 'Brake Output', 'Throttle Output', 'Target Speed', 'Current Speed', 'Output-P', 'Output-I', 'Output-D']
 print(f'Throttle data:\n{throttle_df.head()}\n')
 return throttle_df


def plot_steer_data(steer_df, n_rows):   
 steer_df2 = steer_df[:n_rows]
 steer_df2.plot(x = steer_df.columns[1], y = [steer_df.columns[2], steer_df.columns[3], steer_df.columns[4], steer_df.columns[5]], kind = 'line', style= '.-')

 #steer_cpy = steer_df2[['Sim Time', 'x0 Planned', 'y0 Planned', 'x1 Planned', 'y1 Planned', 'x0 Current', 'y0 Current']]
 #steer_cpy.plot(x = steer_cpy.columns[0], y = [steer_cpy.columns[1], steer_cpy.columns[2], steer_cpy.columns[3], steer_cpy.columns[4], steer_cpy.columns[5], steer_cpy.columns[6]], kind = 'line', style= '.-')
 steer_cpy = steer_df2[['Sim Time', 'Output-P', 'Output-I', 'Output-D']]
 steer_cpy.plot(x = steer_cpy.columns[0], y = [steer_cpy.columns[1], steer_cpy.columns[2], steer_cpy.columns[3]], kind = 'line', style= '.-')

 steer_cpy = steer_df2[['Sim Time', 'x Current', 'y Current', 'x Target', 'y Target']]
 steer_cpy = steer_cpy.to_numpy()
 ax = plt.figure()
 plt.plot(steer_cpy[:, 1], steer_cpy[:, 2], 'b.-')
 plt.plot(steer_cpy[:, 3], steer_cpy[:, 4], 'r.-')
 plt.legend(['Current', 'Target'])
 plt.gca().invert_yaxis()
 
    
def plot_throttle_data(throttle_df, n_rows):   
 throttle_df2 = throttle_df[:n_rows]
 throttle_df2.plot(x = throttle_df.columns[1], y = [throttle_df.columns[2], throttle_df.columns[3], throttle_df.columns[4], throttle_df.columns[5], throttle_df.columns[6]], kind = 'line', style= '.-')
 
 throttle_cpy = throttle_df2[['Sim Time', 'Output-P', 'Output-I', 'Output-D']]
 throttle_cpy.plot(x = throttle_cpy.columns[0], y = [throttle_cpy.columns[1], throttle_cpy.columns[2], throttle_cpy.columns[3]], kind = 'line', style= '.-')
 
    
def main():
 steer_df = read_steer_data()
 throttle_df = read_throttle_data()
 n_rows = -1 #2000
 plot_steer_data(steer_df, n_rows)
 plot_throttle_data(throttle_df, n_rows)
 plt.show()
 
    
if __name__ == '__main__':
    main()
