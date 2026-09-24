#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <type_traits>
#ifndef TEST_FRAMEWORK
#define TEST_FRAMEWORK

inline int g_tests_run = 0;
inline int g_tests_failed = 0;

// ---- stringify helpers ----

// Generic: works for int, string, double, bool, anything with operator
template <typename T>
std::string test_to_string(const T& val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

// Overload for containers (vector, std::array, etc.)
template <typename T, typename = void>
struct has_ostream_op : std::false_type {};

template <typename T>
struct has_ostream_op<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const T&>())>>
    : std::true_type {};

template <typename T>
std::string test_to_string_container(const T& val) {
    std::ostringstream oss;
    oss << "{";
    bool first = true;
    for (const auto& elem : val) {
        if (!first) oss << ", ";
        if constexpr (has_ostream_op<std::decay_t<decltype(elem)>>::value) {
            oss << elem;
        } else {
            oss << test_to_string_container(elem);
        }
        first = false;
    }
    oss << "}";
    return oss.str();
}

// Overload for raw C-style arrays (reference-to-array preserves size N)
template <typename T, std::size_t N>
std::string test_to_string(const T (&val)[N]) {
    std::ostringstream oss;
    oss << "{";
    for (std::size_t i = 0; i < N; ++i) {
        if (i != 0) oss << ", ";
        oss << val[i];
    }
    oss << "}";
    return oss.str();
}

// ---- raw array comparison (== on raw arrays just compares pointers, so we
// need an explicit element-by-element check) ----
template <typename T, std::size_t N>
bool test_array_eq(const T (&a)[N], const T (&b)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        if (!(a[i] == b[i])) return false;
    }
    return true;
}

// ---- macros ----

// Bool checks (works for any type)
// Bool checks (works for any type)
#define CHECK(condition) \
    do { \
        g_tests_run++; \
        if (!(condition)) { \
            g_tests_failed++; \
            std::cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
                      << " - " << #condition << "\n"; \
        } else { \
            std::cout << "[PASS] " << __FILE__ << ":" << __LINE__ \
                       << " - " << #condition << "\n"; \
        } \
    } while (0)

// Scalar equality: int, double, bool, std::string, etc.
#define CHECK_EQ(a, b) \
    do { \
        g_tests_run++; \
        auto va = (a); auto vb = (b); \
        if (!(va == vb)) { \
            g_tests_failed++; \
            std::cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
                      << " - expected " << test_to_string(va) \
                      << " but got " << test_to_string(vb) << "\n"; \
        } else { \
            std::cout << "[PASS] " << __FILE__ << ":" << __LINE__ \
                       << " - " << #a << " == " << test_to_string(va) << "\n"; \
        } \
    } while (0)

// Container equality: std::vector, std::array, std::set, etc.
#define CHECK_VEC_EQ(a, b) \
    do { \
        g_tests_run++; \
        auto va = (a); auto vb = (b); \
        if (!(va == vb)) { \
            g_tests_failed++; \
            std::cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ << " - vectors differ\n"; \
            std::cerr << "  expected: " << test_to_string_container(va) << "\n"; \
            std::cerr << "  actual:   " << test_to_string_container(vb) << "\n"; \
        } else { \
            std::cout << "[PASS] " << __FILE__ << ":" << __LINE__ \
                       << " - " << test_to_string_container(va) << " == " << test_to_string_container(vb) << "\n"; \
        } \
    } while (0)

inline int report_results() {
    std::cout << (g_tests_run - g_tests_failed) << "/" << g_tests_run << " checks passed\n";
    return g_tests_failed == 0 ? 0 : 1;
}

#endif