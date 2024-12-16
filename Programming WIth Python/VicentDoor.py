def door_mat_design(N, M):
    # First half - Pattern lines
    pattern_count = 1
    for i in range(N // 2):
        line = (".|." * pattern_count).center(M, '-')
        print(line)
        pattern_count += 2

    # Middle line - WELCOME
    middle_line = "WELCOME".center(M, '-')
    print(middle_line)

    # Second half - Mirror of the first half
    pattern_count -= 2  # Start with the previous pattern count
    for i in range(N // 2):
        line = (".|." * pattern_count).center(M, '-')
        print(line)
        pattern_count -= 2

# Read input
N, M = map(int, input().split())

# Call the function
door_mat_design(N, M)
