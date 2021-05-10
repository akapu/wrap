import matplotlib.pyplot as plt
import numpy as np

def main():
    points = {}
    hull = []

    with open('IN.txt') as file:
        for line in file:
            line = line.split()
            points[int(line[0])] = {'x': float(line[1]), 'y': float(line[2])}

    with open('out') as file:
        for line in file:
            hull.append(int(line))

    hull.append(hull[0])


    fig, ax = plt.subplots()
    ax.scatter([point['x'] for point in points.values()],
            [point['y'] for point in points.values()])
    ax.plot([points[num]['x'] for num in hull], [points[num]['y'] for num in hull])
    plt.savefig('filename')

    
        


if __name__ == "__main__":
    main()
