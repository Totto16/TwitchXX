test_deps = deps

test_deps += dependency('gtest')


test_files = files(
    'v5/Action.t.cpp',
    'v5/Channel.t.cpp',
    'v5/UserFollows.t.cpp',
    'AppAccessToken.t.cpp',
    'BitsLeaderboard.t.cpp',
    'Clip.t.cpp',
    'Entitlement.t.cpp',
    'Game.t.cpp',
    'Stream.t.cpp',
    'StreamMetadata.t.cpp',
    'TestConstants.h',
    'TestLogger.cpp',
    'TestLogger.h',
    'TestUtils.cpp',
    'TestUtils.h',
    'TwitchXX-Tests.cpp',
    'User.t.cpp',
    'UserAccessToken.t.cpp',
    'UserFollows.t.cpp',
    'Video.t.cpp',
)


TwitchXX_Tests_exe = executable(
    'TwitchXX-Tests',
    test_files,
    dependencies: test_deps,
    include_directories: inc_dirs,
)

test('TwitchXX tests', TwitchXX_Tests_exe)
