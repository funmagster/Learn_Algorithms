planes_info = {}
for _ in range(int(input())):
    plane_name, value = input().split()
    planes_info[plane_name] = int(value)

conditions_info = {}
for _ in range(int(input())):
    plane_name, condition = input().split()
    if plane_name not in conditions_info:
        conditions_info[plane_name] = {}
    if condition not in conditions_info[plane_name]:
        conditions_info[plane_name][condition] = 0
    conditions_info[plane_name][condition] += 1

final_results = {}
for plane_name, condition_counts in conditions_info.items():
    max_count = max(condition_counts.values())
    for condition in sorted(condition_counts.keys()):
        if condition_counts[condition] == max_count:
            if condition not in final_results:
                final_results[condition] = 0
            final_results[condition] += planes_info[plane_name]
            planes_info[plane_name] = 0

for condition, value in sorted(final_results.items(), key=lambda item: (-item[1], item[0])):
    print(condition, value)
