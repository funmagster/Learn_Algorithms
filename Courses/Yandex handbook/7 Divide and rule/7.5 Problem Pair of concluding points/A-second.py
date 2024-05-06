import math


def distance(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)


def brute_force_closest_pair(points):
    min_distance = float('inf')
    closest_pair = None
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            dist = distance(points[i], points[j])
            if dist < min_distance:
                min_distance = dist
                closest_pair = (points[i], points[j])
    return min_distance, closest_pair


def closest_pair(points):
    if len(points) <= 3:
        return brute_force_closest_pair(points)

    sorted_points = sorted(points, key=lambda x: x[0])

    mid = len(sorted_points) // 2
    left_points = sorted_points[:mid]
    right_points = sorted_points[mid:]

    left_min_distance, left_closest_pair = closest_pair(left_points)
    right_min_distance, right_closest_pair = closest_pair(right_points)

    min_distance = min(left_min_distance, right_min_distance)
    min_pair = left_closest_pair if left_min_distance < right_min_distance else right_closest_pair

    strip = []
    mid_x = sorted_points[mid][0]
    for point in sorted_points:
        if abs(point[0] - mid_x) < min_distance:
            strip.append(point)

    strip.sort(key=lambda x: x[1])

    for i in range(len(strip)):
        for j in range(i + 1, len(strip)):
            if strip[j][1] - strip[i][1] >= min_distance:
                break
            dist = distance(strip[i], strip[j])
            if dist < min_distance:
                min_distance = dist
                min_pair = (strip[i], strip[j])

    return min_distance, min_pair


n = int(input())
cords = [tuple(map(int, input().split())) for _ in range(n)]
print(round(closest_pair(cords)[0], 6))
