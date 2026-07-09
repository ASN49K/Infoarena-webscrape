def cel_mai_lung_subsir_comun(subsir1, subsir2):
    # Create DP matrix
    dp = [[0] * (len(subsir1) + 1) for _ in range(len(subsir2) + 1)]
    
    # Fill the DP matrix
    for i in range(1, len(subsir2) + 1):
        for j in range(1, len(subsir1) + 1):
            if subsir1[j-1] == subsir2[i-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    # Get the actual subsequence
    subsequence = []
    i, j = len(subsir2), len(subsir1)
    while i > 0 and j > 0:
        if subsir1[j-1] == subsir2[i-1]:
            subsequence.append(subsir1[j-1])
            i -= 1
            j -= 1
        elif dp[i-1][j] > dp[i][j-1]:
            i -= 1
        else:
            j -= 1
    subsequence.reverse()
    
    return dp[len(subsir2)][len(subsir1)], subsequence

# Read sequences from file
def read_sequences(filename):
    with open(filename, 'r') as f:
        f.readline()
        # Read first line and convert to list of integers
        subsir1 = list(map(int, f.readline().strip().split()))
        # Read second line and convert to list of integers
        subsir2 = list(map(int, f.readline().strip().split()))
    return subsir1, subsir2

# Read input from file
subsir1, subsir2 = read_sequences('cmlsc.in')

# Calculate result
length, subsequence = cel_mai_lung_subsir_comun(subsir1, subsir2)

# Write to file
with open('cmlsc.out', 'w') as f:
    f.write(f"{length}\n")
    for element in subsequence:
        f.write(str(element) + " ")

print("Rezultatele au fost scrise în fișierul 'rezultat_lcs.txt'")