import struct

def read_txt_file(txt_filename):
    with open(txt_filename, 'r') as txt_file:
        lines = txt_file.readlines()
        # Парсинг данных из текстового файла
        vertex_count = int(lines[0])
        vertexes = [[float(v) for v in line.split()] for line in lines[1:vertex_count + 1]]
        edge_count = int(lines[vertex_count + 1])
        edges = [[int(v) for v in line.split()] for line in lines[vertex_count + 2:]]
        return vertexes, edges

def write_bin_file(bin_filename, vertexes, edges):
    with open(bin_filename, 'wb') as bin_file:
        # Запись количества вершин и ребер в бинарный файл
        bin_file.write(struct.pack('Q', len(vertexes)))
        # Запись координат вершин
        for vertex in vertexes:
            bin_file.write(struct.pack('ddd', *vertex))
        bin_file.write(struct.pack('Q', len(edges)))
        # Запись индексов ребер
        for edge in edges:
            bin_file.write(struct.pack('ii', *edge))

def txt_to_bin(txt_filename, bin_filename):
    vertexes, edges = read_txt_file(txt_filename)
    write_bin_file(bin_filename, vertexes, edges)

if __name__ == "__main__":
    txt_filename = 'data\cube.txt'
    bin_filename = 'data\cube.bin'
    txt_to_bin(txt_filename, bin_filename)
    print(f"Data from '{txt_filename}' has been converted and saved to '{bin_filename}' in binary format.")
