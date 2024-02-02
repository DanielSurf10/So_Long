import os

maps = os.listdir("maps")

for map_file in maps:
    print(f"\nMap: {map_file}\n")
    os.system(f"./so_long maps/{map_file}")
    print()
