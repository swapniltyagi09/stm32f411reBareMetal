assembly_code = """
LOAD R0, 5
LOAD R1, 3
ADD R0, R1
"""

# Define the instruction mapping
opcodes = {
    "NOP":  "0000",
    "LOAD": "0001",
    "ADD":  "0010",
    "SUB":  "0011",
    "AND":  "0100",
    "OR":   "0101"
}

# Convert assembly to machine code
def assemble(code):
    lines = code.strip().split("\n")
    machine_code = []
    
    for line in lines:
        parts = line.split()
        opcode = opcodes.get(parts[0], "0000")
        reg = format(int(parts[1][1]), '02b')  # Convert register (R0, R1) to binary
        data = format(int(parts[2]), '06b') if parts[0] == "LOAD" else format(int(parts[2][1]), '02b')
        
        machine_code.append(f"{opcode}{reg}{data}")

    return machine_code

binary_code = assemble(assembly_code)

# Save machine code to a file
with open("machine_code.txt", "w") as f:
    for line in binary_code:
        f.write(line + "\n")

print("\n".join(binary_code))
