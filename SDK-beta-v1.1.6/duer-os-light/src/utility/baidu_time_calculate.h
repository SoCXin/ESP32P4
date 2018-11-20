// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhang Guohua (zhangguohua02@baidu.com)
//
// Description: Time calculate

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIME_CALCULATE_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIME_CALCULATE_H

#ifdef __cplusplus
extern "C" {
#endif

void add_measure_value(int key, int count);
void update_measure_value(int key, int arg_value, int continuous_measure_flag);
void output_measure_result();

enum baidu_time_measure_params {
    // TIME_END will measure time no matter there is a one-to-one TIME_BEGIN or not
    CONTINUOUS_TIME_MEASURE = 0,
    // TIME_END will measure time only when there is a one-to-one TIME_BEGIN
    UNCONTINUOUS_TIME_MEASURE = 1,
    MAX_TIME_CALCULATE_COUNT = 0X7FFFFFFF,
};

#define TIME_BEGIN(KEY, COUNTER) do{\
	add_measure_value(KEY, COUNTER);\
}while(0)

#define TIME_END(KEY, ARGUEMENT, FLAG) do{\
	update_measure_value(KEY, ARGUEMENT, FLAG);\
}while(0)

#define TIME_RESULT() do{\
	output_measure_result();\
}while(0)

enum baidu_perform_statistic_watch_point {
    PERFORM_STATISTIC_START_RECORD = 1,  // from user press start button to start record
    PERFORM_STATISTIC_RECORDER_ON_DATA,  // time consume of encode and send record data
    PERFORM_STATISTIC_READ_VOICE_DATA,   // time consume of read voice data from arm
    PERFORM_STATISTIC_SOTP_RECORD,       // from user stop record to the recorder thread stop
    PERFORM_STATISTIC_BASE64_ENCODE,     // the time consume of mbedtls_base64_encode
    PERFORM_STATISTIC_GET_URL,           // the time from user stop record to get media data from URL
    // time consume of recorder_output_handler(encode and pass to CA)
    PERFORM_STATISTIC_OUTPUT_RECORDER_DATA,
    // time consume of bdspx_speex_encode encode data(exclude output encoded data)
    PERFORM_STATISTIC_SPEEX_ENCODE,
    PERFORM_STATISTIC_GET_MEDIA_BY_URL,  // time consume from get media data from url to play it
    PERFORM_STATISTIC_PLAY_URL_MEDIA,    // time consume of mdm_media_data_out_handler(play url data)
    PERFORM_STATISTIC_GET_MEDIA_BY_PATH, // time consume of read local media
    PERFORM_STATISTIC_PLAY_LOCAL_MEDIA,  // time consume of mdm_media_data_out_handler(play local data)
    PERFORM_STATISTIC_WATCH_POINT_NUM,
};

#ifndef RELEASE_VERSION
#define BAIDU_PERFORM_STATISTIC
#endif

//**************************************************************************************//
//	KEY is value in baidu_perform_statistic_watch_point.
//	COUNTER is the biggest measurement times.
//	ARGUEMENT is used for speed as ARGUEMENT/TIME_AVERAGE.
//
//	PERFORM_STATISTIC_BEGIN(1, 10);
//	printf("ABC");
//	PERFORM_STATISTIC_END(1, 200, UNCONTINUOUS_TIME_MEASURE);
//
//	You can call PERFORM_STATISTIC_RESULT() anywhere to print the resutl.
//
//**************************************************************************************//

#ifdef BAIDU_PERFORM_STATISTIC
#define PERFORM_STATISTIC_BEGIN(KEY, COUNTER) TIME_BEGIN(KEY, COUNTER)
#define PERFORM_STATISTIC_END(KEY, ARGUEMENT, FLAG) TIME_END(KEY, ARGUEMENT, FLAG)
#define PERFORM_STATISTIC_RESULT() TIME_RESULT()
#else
#define PERFORM_STATISTIC_BEGIN(KEY, COUNTER)
#define PERFORM_STATISTIC_END(KEY, ARGUEMENT, FLAG)
#define PERFORM_STATISTIC_RESULT()
#endif

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIME_CALCULATE_H

