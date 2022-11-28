def factorial (num: int):
    total = 1
    for i in range(2, num + 1):
        total *= i
    return total

foo: list[str] = ["hello", "world"]
#bar: dict[str, int]
bar: list[tuple[str, int]] = [("Martijn", 1), ("Marleen", 2)]
baz: dict[int, dict[int, dict[int, str]]]
