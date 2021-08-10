from sys import stdin

def main():
    output = ""
    for x in stdin:
        if int(x) == 0: break
        binary = bin(int(x))
        result = len(binary) - len(binary.strip("1")) # 計算尾端 1 的數量來判定進位
        output += f"{result}\n"
    print(output.strip()) # 移除最後一個換行符號避免 NA

main()