// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once
#include "webrtc.PeerConnection.PeerConnection.g.h"

namespace winrt::Microsoft::WinRTC::WebRtcWrapper::webrtc::PeerConnection::implementation
{
struct PeerConnection : PeerConnectionT<PeerConnection>
{

  PeerConnection();
  ~PeerConnection();
  //PeerConnection() = default;

  PeerConnection(::rtc::scoped_refptr<::webrtc::PeerConnectionInterface> webrtc_peer_connection);

  bool AddIceCandidate(Microsoft::WinRTC::WebRtcWrapper::webrtc::IceCandidate const &value);

  void SetLocalDescription(Microsoft::WinRTC::WebRtcWrapper::webrtc::SetSessionDescriptionObserver const &observer,
                           Microsoft::WinRTC::WebRtcWrapper::webrtc::SessionDescription const &desc);

  void SetRemoteDescription(Microsoft::WinRTC::WebRtcWrapper::webrtc::SetSessionDescriptionObserver const &observer,
                            Microsoft::WinRTC::WebRtcWrapper::webrtc::SessionDescription const &desc);

  Microsoft::WinRTC::WebRtcWrapper::webrtc::RtpSender AddAudioTrack(
      Microsoft::WinRTC::WebRtcWrapper::webrtc::AudioTrack const &track,
      Windows::Foundation::Collections::IVector<hstring> const &stream_ids);

  Microsoft::WinRTC::WebRtcWrapper::webrtc::RtpSender AddVideoTrack(
      Microsoft::WinRTC::WebRtcWrapper::webrtc::VideoTrack const &track,
      Windows::Foundation::Collections::IVector<hstring> const &stream_ids);

  void CreateOffer(Microsoft::WinRTC::WebRtcWrapper::webrtc::CreateSessionDescriptionObserver const &observer,
                   Microsoft::WinRTC::WebRtcWrapper::webrtc::PeerConnection::RTCOfferAnswerOptions const &options);

  void CreateAnswer(Microsoft::WinRTC::WebRtcWrapper::webrtc::CreateSessionDescriptionObserver const &observer,
                    Microsoft::WinRTC::WebRtcWrapper::webrtc::PeerConnection::RTCOfferAnswerOptions const &options);
  Microsoft::WinRTC::WebRtcWrapper::webrtc::DataChannel CreateDataChannel(
      hstring const &label, Microsoft::WinRTC::WebRtcWrapper::webrtc::DataChannelInit const &config);

private:
  ::rtc::scoped_refptr<::webrtc::PeerConnectionInterface> webrtc_peer_connection_;
};
} // namespace winrt::Microsoft::WinRTC::WebRtcWrapper::webrtc::PeerConnection::implementation
namespace winrt::Microsoft::WinRTC::WebRtcWrapper::webrtc::PeerConnection::factory_implementation
{
struct PeerConnection : PeerConnectionT<PeerConnection, implementation::PeerConnection>
{
};
} // namespace winrt::Microsoft::WinRTC::WebRtcWrapper::webrtc::PeerConnection::factory_implementation