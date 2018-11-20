#ifndef BAIDU_SPEEX_H
#define BAIDU_SPEEX_H


#ifdef __cplusplus
extern "C" {
#endif

/**
TYPE:
typedef void (*bdspx_output_hdlr_t)(char *p_spx_buf, int n_bytes, int b_flush)

DESC:
callback to output speex data 

PARAM:
@param[in] p_spx_buf: speex buffer to output
@param[in] n_bytes: speex buffer length 
@param[in] b_flush: to flush all speex data to output
*/
typedef void (*bdspx_output_hdlr_t)(void *ctx, char *p_spx_buf, int n_bytes, int b_flush);

int bdspx_speex_init(int n_sample_rate, void **buf);
int bdspx_speex_encode(char *p_pcm_buff, int *p_len, int n_end, bdspx_output_hdlr_t output_hdlr, void *ctx, void *buf);
void bdspx_speex_destroy(void *buf);
#ifdef __cplusplus
}
#endif


#endif







