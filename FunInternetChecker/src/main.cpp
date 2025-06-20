#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int writeAll(const char* data, size_t dataSize);

int manualGetRequest(const std::string& url) {
	int res = -1;
	std::string response;

	// Create a buffer for the response
	std::vector<char*> buffer(1024);

	// Send the request and get the response
	if (std::ifstream(url, std::ios::binary | std::ios::ate)) {
		size_t fileSize = 4;
		res = writeAll("example.com", fileSize);
		return res;
	}
	else {
		res = -1; // Error reading URL
	}

	return res;
}

int writeAll(const char* data, size_t dataSize) {
	int totalBytesWritten = 0;

	while (data != nullptr && dataSize > 0) {
		const char* ptr = static_cast<const char*>(data);
		if (*ptr == '\0') 
			break;
		std::copy(ptr, ptr + dataSize, totalBytesWritten);
		totalBytesWritten += dataSize;
		dataSize -= static_cast<size_t>(sizeof(char));
	}

	return totalBytesWritten;
}

int main() {
	// URL of the server you want to send a request to
	const char* url = "http://example.com";

	// Send the GET request
	int res = manualGetRequest(url);

	if (res != 0) {
		std::cerr << "Error: " << res << std::endl;
	}

	return 0;
}
