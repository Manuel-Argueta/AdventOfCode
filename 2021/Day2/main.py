
#Part 2
def main():
    movesArr = []
    x,d,aim = 0,0,0
    with open('input.txt') as f:
        while True:
            line = f.readline()
            if not line:
                break
            movesArr.append(line.split())

    #loops through 2d array of instruction arrays where arr[x][0] the instruction string and arr[x][1] 
    #the numerical value to find final depth and horizontal position
    for i in range(len(movesArr)):
        if (movesArr[i][0] == "forward"):
            x += int(movesArr[i][1])
            d += int(movesArr[i][1])*aim
        elif (movesArr[i][0] == "down"):
            aim += int(movesArr[i][1])
        elif (movesArr[i][0] == "up"):
            aim -= int(movesArr[i][1])
    print(x*d)

if __name__ == "__main__":
    main()


# Part 1
# def main():
#     movesArr = []
#     x,d = 0,0
#     with open('input.txt') as f:
#         while True:
#             line = f.readline()
#             if not line:
#                 break
#             movesArr.append(line.split())
#     for i in range(len(movesArr)):
#         if (movesArr[i][0] == "forward"):
#             x += int(movesArr[i][1])
#         elif (movesArr[i][0] == "down"):
#             d += int(movesArr[i][1])
#         elif (movesArr[i][0] == "up"):
#             d -= int(movesArr[i][1])
#     print(x*d)

# if __name__ == "__main__":
#     main()
