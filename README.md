# Navigator
searches for the shortest route by analyzing the given map


# Input
The first line of input will contain the dimensions of the map: width w and height h.
The next h lines (each containing w characters) will describe the map. Each character in the description is a dot (.)
representing an empty field, a cross (#) representing a road, an asterisk (*) representing a city, or a letter or number that is part of the city name.
The next line will contain a single integer k - the number of flight connections.
The next k lines will describe the connections in the format source destination time, where source is the name of the starting city,
destination is the name of the destination city, and time is the flight time in minutes. The next line will contain a single integer
q - the number of queries. Each query will appear on a separate line and will have the format source destination type. This is a query
for the shortest travel time from the source city to the destination city. If the type is zero, the query is only for the time. 
If the type is one, the route should also be provided.

# Output
For each query, output one line. At the beginning of the line should be the number representing the shortest travel time between the cities.
If the query has a type of one, all intermediate cities (excluding the starting and ending cities) should also be listed in the order they were visited,
separated by spaces.

# Example:
![Example of input and output](https://github.com/ArtemDychenko/Navigator/assets/134294885/d8b206a1-9696-435a-afa3-9bd7b79b57b7)
