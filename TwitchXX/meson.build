

if get_option('docs').allowed()


    # #TODO improove

    # doxygen_prog = find_program('doxygen', required: get_option('docs'))

    # doxygen_in = [meson.current_source_dir() / 'docs/Doxyfile.in']
    # doxygen_out = [meson.current_source_dir() / 'Doxyfile']

    # #add_definitions(-D_DEBUG)
    # # request to configure the file
    # # configure_file([doxygen_in, doxygen_out, '@ONLY'])
    # # message('Doxygen build started')
    # # note the option ALL which allows to build the docs together with the application
    # # add_custom_target(['doc_doxygen', 'ALL', 'COMMAND', doxygen_executable, doxygen_out, 'WORKING_DIRECTORY', cmake_current_binary_dir, 'COMMENT', 'Generating API documentation with Doxygen', 'VERBATIM'])
    # docs = custom_target(
    #     'build-docs',
    #     command: [doxygen_prog, '@INPUT@'],
    #     input: doxygen_in,
    #     output: doxygen_out,
    # )


endif


src_files += files(
    'Auth/AppAccessToken.cpp',
    'Auth/AppAccessToken.h',
    'Auth/AuthToken.h',
    'Auth/UserAccessToken.cpp',
    'Auth/UserAccessToken.h',
    'v5/Action.cpp',
    'v5/Action.h',
    'v5/Channel.cpp',
    'v5/Channel.h',
    'v5/Commercial.cpp',
    'v5/Commercial.h',
    'v5/Community.cpp',
    'v5/Community.h',
    'v5/Create.h',
    'v5/Subscription.cpp',
    'v5/Subscription.h',
    'v5/Team.cpp',
    'v5/Team.h',
    'v5/User.cpp',
    'v5/User.h',
    'v5/UserFollows.cpp',
    'v5/UserFollows.h',
    'v5/Video.cpp',
    'v5/Video.h',
    'Api.cpp',
    'Api.h',
    'BitsLeaderboardEntry.cpp',
    'BitsLeaderboardEntry.h',
    'BitsLeaderboardOptions.cpp',
    'BitsLeaderboardOptions.h',
    'BroadcasterType.cpp',
    'BroadcasterType.h',
    'Clip.cpp',
    'Clip.h',
    'ClipOptions.cpp',
    'ClipOptions.h',
    'Direction.cpp',
    'Direction.h',
    'Entitlement.cpp',
    'Entitlement.h',
    'Game.cpp',
    'Game.h',
    'JsonWrapper.h',
    'Log.cpp',
    'Log.h',
    'Logger.cpp',
    'Logger.h',
    'MakeRequest_Impl.cpp',
    'MakeRequest_Impl.h',
    'PeriodType.cpp',
    'PeriodType.h',
    'Request.cpp',
    'Request.h',
    'RequestOnce.cpp',
    'RequestOnce.h',
    'RequestParams.cpp',
    'RequestParams.h',
    'RequestWait.cpp',
    'RequestWait.h',
    'Stream.cpp',
    'Stream.h',
    'StreamMetadata.cpp',
    'StreamMetadata.h',
    'StreamType.cpp',
    'StreamType.h',
    'StreamsOptions.cpp',
    'StreamsOptions.h',
    'TwitchDef.h',
    'TwitchException.h',
    'User.cpp',
    'User.h',
    'UserFollows.cpp',
    'UserFollows.h',
    'UserType.cpp',
    'UserType.h',
    'Utility.cpp',
    'Utility.h',
    'UtilsInternal.cpp',
    'UtilsInternal.h',
    'Video.cpp',
    'Video.h',
    'VideoOptions.cpp',
    'VideoOptions.h',
    'VideoSortType.cpp',
    'VideoSortType.h',
    'VideoType.cpp',
    'VideoType.h',
)

inc_dirs += include_directories('.', 'v5', 'Auth')
