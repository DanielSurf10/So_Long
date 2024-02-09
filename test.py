import os


maps = os.listdir("maps/valid")

print("-" * 50)
print("Mapas válidos")
print("-" * 50)
for map_file in maps:
    print(f"\nMap: {map_file}")
    os.system(f"./so_long maps/valid/{map_file}")
    print()


maps = os.listdir("maps/invalid")

print("-" * 50)
print("Mapas inválidos")
print("-" * 50)
for map_file in maps:
    print(f"\nMap: {map_file}")
    os.system(f"./so_long maps/invalid/{map_file}")
    print()
