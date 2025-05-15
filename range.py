x = range(0, 10, 2)

print(type(x))

print(x)

print(x.__iter__().__next__())

it = iter(x)

print(it.__next__())
print(it.__next__())
print(it.__next__())

print(it.__next__())
print(it.__next__())


print(x)

it2 = iter(x)
print(it2.__next__())
print(it2.__next__())


# Python's range class generates an immutable sequence of numbers.
# Usage:
#   range(stop)           -> numbers from 0 up to (but not including) stop
#   range(start, stop)    -> numbers from start up to (but not including) stop
#   range(start, stop, step) -> numbers from start to stop, incremented by step
#
# Example:
#   range(0, 10, 2) produces: 0, 2, 4, 6, 8
#
# range objects are memory efficient and do not store all values at once.
# They support iteration, indexing, length, and membership tests.
# You can convert a range to a list with list(range(...)).
#
# Common methods and attributes:
#   - start, stop, step: show the range's parameters
#   - __iter__(): returns an iterator over the range
#   - __getitem__(index): get item at position index
#   - __contains__(value): check if value is in range
#   - count(value): count occurrences of value (0 or 1)
#   - index(value): get index of value or raise ValueError