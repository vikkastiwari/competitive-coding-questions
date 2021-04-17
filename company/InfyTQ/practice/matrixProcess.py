def transpose(matrix):
    trans_matrix = []
    for col in range(len(matrix[0])):
        trans = []
        for row in range(len(matrix)):
            trans.append(matrix[row][col])
        trans_matrix.append(trans)
    return trans_matrix


def count_freq(list):
    count = {}
    for each in list:
        if each in count:
            count[each] += 1
        else:
            count[each] = 1
    for key, value in count.items():
        if(value >= 4):
            return key


def get_rows(matrix):
    return [[c for c in r] for r in matrix]


def get_cols(matrix):
    return zip(*matrix)


def diagonal(matrix):
    arr = [None] * (len(matrix) - 1)
    matrix = [arr[i:] + row + arr[:i]
              for i, row in enumerate(get_rows(matrix))]
    return [[col for col in row if col is not None] for row in get_cols(matrix)]


frequencies = []
matrix = []

# number of rows
row = int(input())

# input of matrix
for each in range(row):
    array = list(map(int, input().split()))
    matrix.append(array)
print("matrix: ", matrix)

# counting frequencies of elements row wise in matrix
for arr in matrix:
    frequencies.append(count_freq(arr))

# transposed matrix
trans_matrix = transpose(matrix)
print("Transposed: ", trans_matrix)

# counting frequencies of elements row wise in transposed matrix
for arr in trans_matrix:
    frequencies.append(count_freq(arr))

# processing matrix to store diagonals
matrix_diagonal = diagonal(matrix)
print("Diagonal: ", matrix_diagonal)

# counting frequencies of elements diagonally in processed matrix
for arr in matrix_diagonal:
    frequencies.append(count_freq(arr))

frequencies = [each for each in frequencies if each]
if len(frequencies) == 0:
    print('-1')
else:
    print(min(frequencies))
