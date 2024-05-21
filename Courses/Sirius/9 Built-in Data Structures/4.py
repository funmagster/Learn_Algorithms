def schedule_lesson(occupied_teachers, occupied_classrooms, lesson_teachers, lesson_classrooms):
    if occupied_teachers & lesson_teachers or lesson_classrooms <= occupied_classrooms:
        return -1

    updated_teachers = occupied_teachers.union(lesson_teachers)
    available_classrooms = lesson_classrooms.difference(occupied_classrooms)
    allocated_classroom = min(available_classrooms)
    occupied_classrooms.add(allocated_classroom)

    return updated_teachers, occupied_classrooms


n = int(input())
occupied_teachers = set(map(int, input().split()))
n2 = int(input())
occupied_classrooms = set(map(int, input().split()))
n3 = int(input())
lesson_teachers = set(map(int, input().split()))
n4 = int(input())
lesson_classrooms = set(map(int, input().split()))

result = schedule_lesson(occupied_teachers, occupied_classrooms, lesson_teachers, lesson_classrooms)
if result == -1:
    print(result)
else:
    updated_teachers, updated_classrooms = result
    print(len(updated_teachers))
    print(' '.join(map(str, sorted(updated_teachers))))
    print(len(updated_classrooms))
    print(' '.join(map(str, sorted(updated_classrooms))))
