#ifndef UI_LATENCY_UI_LATENCY_EXPORT_H_
#define UI_LATENCY_UI_LATENCY_EXPORT_H_

#if defined(COMPONENT_BUILD)
#if defined(WIN32)

#if defined(UI_LATENCY_IMPLEMENTATION)
#define UI_LATENCY_EXPORT __declspec(dllexport)
#else
#define UI_LATENCY_EXPORT __declspec(dllimport)
#endif  // defined(UI_LATENCY_IMPLEMENTATION)

#else  // defined(WIN32)
#if defined(UI_LATENCY_IMPLEMENTATION)
#define UI_LATENCY_EXPORT __attribute__((visibility("default")))
#else
#define UI_LATENCY_EXPORT
#endif
#endif

#else  // defined(COMPONENT_BUILD)
#define UI_LATENCY_EXPORT
#endif

#endif  // UI_LATENCY_UI_LATENCY_EXPORT_H_
