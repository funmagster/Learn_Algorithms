import os
from tqdm import tqdm
from dfs.dfs import main_dfs


def list_files(directory):
    if not os.path.isdir(directory):
        print(f"{directory} не является директорией.")
        return

    testing_file = []
    for root, dirs, files in os.walk(directory):
        add_files = [root, {'in': None, 'out': None}]
        for file in files:
            name = file.split('_')[1]
            if name == 'input':
                add_files[1]['in'] = os.path.join(root, file)
            elif name == 'output':
                add_files[1]['out'] = os.path.join(root, file)
            else:
                raise ValueError(f"{file} не содержит 'input' или 'output' после первого _")
        testing_file.append(add_files)
    return testing_file[1:]


def test_dfs(directory_to_test=r'test\test_in_out\evaluation\dfs'):
    if not directory_to_test is None:
        files = list_files(directory_to_test)
        if not files is None:
            for file in tqdm(files):
                with open(file[1]['in'], 'r') as file_in:
                    inputs = file_in.read().split('\n')
                with open(file[1]['out'], 'r') as file_in:
                    outputs_real = list(map(int, file_in.readlines()))
                n, way = map(int, inputs[0].split())
                if way == 1:
                    graph = [[] for _ in range(n)]
                    for edge in range(1, len(inputs)):
                        u, v = map(int, inputs[edge].split())
                        graph[u].append(v)
                        graph[v].append(u)
                elif way == 2:
                    graph = [[0 for _ in range(n)] for __ in range(n)]
                    for edge in range(1, len(inputs)):
                        u, v = map(int, inputs[edge].split())
                        graph[u][v] = 1
                        graph[v][u] = 1
                else:
                    raise ValueError(f'не найден такой way - {way}')
                output_code = main_dfs(graph, way, n)
                print(output_code)
                print(outputs_real)
                assert output_code == outputs_real

            print("Тестирование DFS прошло успешно!")


if __name__ == '__main__':
    test_dfs()