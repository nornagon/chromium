// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/gl/gpu_switching_manager.h"

namespace {

bool g_use_transparent = false;

}  // namespace

namespace ui {

// static
GpuSwitchingManager* GpuSwitchingManager::GetInstance() {
  return base::Singleton<GpuSwitchingManager>::get();
}

// static
void GpuSwitchingManager::SetTransparent(bool transparent) {
  g_use_transparent = transparent;
}

// static
bool GpuSwitchingManager::UseTransparent() {
  return g_use_transparent;
}

GpuSwitchingManager::GpuSwitchingManager() {}

GpuSwitchingManager::~GpuSwitchingManager() {}

void GpuSwitchingManager::AddObserver(GpuSwitchingObserver* observer) {
  observer_list_.AddObserver(observer);
}

void GpuSwitchingManager::RemoveObserver(GpuSwitchingObserver* observer) {
  observer_list_.RemoveObserver(observer);
}

void GpuSwitchingManager::NotifyGpuSwitched() {
  for (GpuSwitchingObserver& observer : observer_list_)
    observer.OnGpuSwitched();
}

}  // namespace ui
