/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <string>
#include <vector>

#include "guiinfo/MusicGUIInfo.h"
#include "guiinfo/PlayerGUIInfo.h"
#include "guiinfo/SystemGUIInfo.h"
#include "guiinfo/VideoGUIInfo.h"
#include "guiinfo/WeatherGUIInfo.h"

class CFileItem;
class CGUIListItem;

struct AudioStreamInfo;
struct VideoStreamInfo;

namespace GUIINFO
{

class GUIInfo;
class IGUIInfoProvider;

class CGUIInfoProviders
{
public:
  CGUIInfoProviders();
  virtual ~CGUIInfoProviders();

  /*!
   * @brief Register a guiinfo provider.
   * @param provider The provider to register.
   */
  void RegisterProvider(IGUIInfoProvider *provider);

  /*!
   * @brief Unregister a guiinfo provider.
   * @param provider The provider to unregister.
   */
  void UnregisterProvider(IGUIInfoProvider *provider);

  /*!
   * @brief Get a GUIInfoManager label string from one of the registered providers.
   * @param value Will be filled with the requested value.
   * @param item The item to get the value for.
   * @param info The GUI info (label id + additional data).
   * @param fallback A fallback value. Can be nullptr.
   * @return True if the value was filled successfully by one of the providers, false otherwise.
   */
  bool GetLabel(std::string& value, const CFileItem *item, const GUIInfo &info, std::string *fallback) const;

  /*!
   * @brief Get a GUIInfoManager integer value from one of the registered providers.
   * @param value Will be filled with the requested value.
   * @param item The item to get the value for.
   * @param info The GUI info (label id + additional data).
   * @return True if the value was filled successfully by one of the providers, false otherwise.
   */
  bool GetInt(int& value, const CGUIListItem *item, const GUIInfo &info) const;

  /*!
   * @brief Get a GUIInfoManager bool value from one of the registered providers.
   * @param value Will be filled with the requested value.
   * @param item The item to get the value for.
   * @param info The GUI info (label id + additional data).
   * @return True if the value was filled successfully by one of the providers, false otherwise.
   */
  bool GetBool(bool& value, const CGUIListItem *item, const GUIInfo &info) const;

  /*!
   * @brief Set new audio/video stream info data at all registered providers.
   * @param audioInfo New audio stream info.
   * @param videoInfo New video stream info.
   */
  void UpdateAVInfo(const AudioStreamInfo& audioInfo, const VideoStreamInfo& videoInfo);

  /*!
   * @brief Get the player guiinfo provider.
   * @return The player guiinfo provider.
   */
  CPlayerGUIInfo& GetPlayerInfoProvider() { return m_playerGUIInfo; }

  /*!
   * @brief Get the system guiinfo provider.
   * @return The system guiinfo provider.
   */
  CSystemGUIInfo& GetSystemInfoProvider() { return m_systemGUIInfo; }

private:
  std::vector<IGUIInfoProvider *> m_providers;

  CMusicGUIInfo m_musicGUIInfo;
  CVideoGUIInfo m_videoGUIInfo;
  CPlayerGUIInfo m_playerGUIInfo;
  CWeatherGUIInfo m_weatherGUIInfo;
  CSystemGUIInfo m_systemGUIInfo;
};

} // namespace GUIINFO
