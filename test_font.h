#ifndef TEST_FASTNOISELITE_H
#define TEST_FASTNOISELITE_H


#include "tests/test_macros.h"
#include "modules/noise/fastnoise_lite.h"
#include "thirdparty/noise/FastNoiseLite.h"


namespace TestFastNoiseLite {

    // GENERAL NOISE SETTINGS

    TEST_CASE("[FastNoiseLite] Testing NoiseType") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());


        noiselite->set_noise_type(noiselite->TYPE_SIMPLEX);
        CHECK(noiselite->get_noise_type() == noiselite->TYPE_SIMPLEX);

        noiselite->set_noise_type(noiselite->TYPE_SIMPLEX_SMOOTH);
        CHECK(noiselite->get_noise_type() == noiselite->TYPE_SIMPLEX_SMOOTH);

        noiselite->set_noise_type(noiselite->TYPE_CELLULAR);
        CHECK(noiselite->get_noise_type() == noiselite->TYPE_CELLULAR);

        noiselite->set_noise_type(noiselite->TYPE_PERLIN);
        CHECK(noiselite->get_noise_type() == noiselite->TYPE_PERLIN);

        noiselite->set_noise_type(noiselite->TYPE_VALUE_CUBIC);
        CHECK(noiselite->get_noise_type() == noiselite->TYPE_VALUE_CUBIC);

        noiselite->set_noise_type(noiselite->TYPE_VALUE);
        CHECK(noiselite->get_noise_type() == noiselite->TYPE_VALUE);


    }

    TEST_CASE("[FastNoiseLite] Testing Seed, Frequency, Offset") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_seed(45);
        CHECK(noiselite->get_seed() == 45);

        noiselite->set_frequency(0.056);
        CHECK(noiselite->get_frequency() == real_t(0.056));

        Vector3 offset = Vector3(1, 2, 3);
        noiselite->set_offset(offset);
        CHECK(noiselite->get_offset() == offset);

    }

    // Fractal Specific

    TEST_CASE("[FastNoiseLite] Fractal Type") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_fractal_type(noiselite->FRACTAL_NONE);
        CHECK(noiselite->get_fractal_type() == noiselite->FRACTAL_NONE);

        noiselite->set_fractal_type(noiselite->FRACTAL_FBM);
        CHECK(noiselite->get_fractal_type() == noiselite->FRACTAL_FBM);

        noiselite->set_fractal_type(noiselite->FRACTAL_RIDGED);
        CHECK(noiselite->get_fractal_type() == noiselite->FRACTAL_RIDGED);

        noiselite->set_fractal_type(noiselite->FRACTAL_PING_PONG);
        CHECK(noiselite->get_fractal_type() == noiselite->FRACTAL_PING_PONG);

    }

    TEST_CASE("[FastNoiseLite] Fractal Octaves, Lacunarity, Gain, Weighted Strength, Ping Pong Strength") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_fractal_octaves(45);
        CHECK(noiselite->get_fractal_octaves() == 45);

        noiselite->set_fractal_lacunarity(0.056);
        CHECK(noiselite->get_fractal_lacunarity() == real_t(0.056));

        noiselite->set_fractal_gain(0.056);
        CHECK(noiselite->get_fractal_gain() == real_t(0.056));

        noiselite->set_fractal_weighted_strength(0.056);
        CHECK(noiselite->get_fractal_weighted_strength() == real_t(0.056));

        noiselite->set_fractal_ping_pong_strength(0.056);
        CHECK(noiselite->get_fractal_ping_pong_strength() == real_t(0.056));

    }

    // Cellular Specific

    TEST_CASE("[FastNoiseLite] Cellular Distance Function") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_cellular_distance_function(noiselite->DISTANCE_EUCLIDEAN);
        CHECK(noiselite->get_cellular_distance_function() == noiselite->DISTANCE_EUCLIDEAN);

        noiselite->set_cellular_distance_function(noiselite->DISTANCE_EUCLIDEAN_SQUARED);
        CHECK(noiselite->get_cellular_distance_function() == noiselite->DISTANCE_EUCLIDEAN_SQUARED);

        noiselite->set_cellular_distance_function(noiselite->DISTANCE_MANHATTAN);
        CHECK(noiselite->get_cellular_distance_function() == noiselite->DISTANCE_MANHATTAN);

        noiselite->set_cellular_distance_function(noiselite->DISTANCE_HYBRID);
        CHECK(noiselite->get_cellular_distance_function() == noiselite->DISTANCE_HYBRID);

    }

    TEST_CASE("[FastNoiseLite] Cellular Return Type") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_cellular_return_type(noiselite->RETURN_CELL_VALUE);
        CHECK(noiselite->get_cellular_return_type() == noiselite->RETURN_CELL_VALUE);

        noiselite->set_cellular_return_type(noiselite->RETURN_DISTANCE);
        CHECK(noiselite->get_cellular_return_type() == noiselite->RETURN_DISTANCE);

        noiselite->set_cellular_return_type(noiselite->RETURN_DISTANCE2);
        CHECK(noiselite->get_cellular_return_type() == noiselite->RETURN_DISTANCE2);

        noiselite->set_cellular_return_type(noiselite->RETURN_DISTANCE2_ADD);
        CHECK(noiselite->get_cellular_return_type() == noiselite->RETURN_DISTANCE2_ADD);

        noiselite->set_cellular_return_type(noiselite->RETURN_DISTANCE2_SUB);
        CHECK(noiselite->get_cellular_return_type() == noiselite->RETURN_DISTANCE2_SUB);

        noiselite->set_cellular_return_type(noiselite->RETURN_DISTANCE2_MUL);
        CHECK(noiselite->get_cellular_return_type() == noiselite->RETURN_DISTANCE2_MUL);

        noiselite->set_cellular_return_type(noiselite->RETURN_DISTANCE2_DIV);
        CHECK(noiselite->get_cellular_return_type() == noiselite->RETURN_DISTANCE2_DIV);
    }

    TEST_CASE("[FastNoiseLite] Cellular Jitter") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_cellular_jitter(0.056);
        CHECK(noiselite->get_cellular_jitter() == real_t(0.056));

    }

    // Domain warp specific

    TEST_CASE("[FastNoiseLite] Domain Warp Enabled, Warp Amplitude, Warp Frequency, Warp Fractal Octaves, Fractal Lacumarity, Fractal Gain") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_domain_warp_enabled(true);
        CHECK(noiselite->is_domain_warp_enabled() == true);

        noiselite->set_domain_warp_amplitude(0.056);
        CHECK(noiselite->get_domain_warp_amplitude() == real_t(0.056));

        noiselite->set_domain_warp_frequency(0.056);
        CHECK(noiselite->get_domain_warp_frequency() == real_t(0.056));

        noiselite->set_domain_warp_fractal_octaves(45);
        CHECK(noiselite->get_domain_warp_fractal_octaves() == 45);

        noiselite->set_domain_warp_fractal_lacunarity(0.056);
        CHECK(noiselite->get_domain_warp_fractal_lacunarity() == real_t(0.056));

        noiselite->set_domain_warp_fractal_gain(0.056);
        CHECK(noiselite->get_domain_warp_fractal_gain() == real_t(0.056));

    }

    TEST_CASE("[FastNoiseLite] Domain Warp Type") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_domain_warp_type(noiselite->DOMAIN_WARP_SIMPLEX);
        CHECK(noiselite->get_domain_warp_type() == noiselite->DOMAIN_WARP_SIMPLEX);

        noiselite->set_domain_warp_type(noiselite->DOMAIN_WARP_SIMPLEX_REDUCED);
        CHECK(noiselite->get_domain_warp_type() == noiselite->DOMAIN_WARP_SIMPLEX_REDUCED);

        noiselite->set_domain_warp_type(noiselite->DOMAIN_WARP_BASIC_GRID);
        CHECK(noiselite->get_domain_warp_type() == noiselite->DOMAIN_WARP_BASIC_GRID);
    }

    TEST_CASE("[FastNoiseLite] Domain Warp Fractal Type") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());

        noiselite->set_domain_warp_fractal_type(noiselite->DOMAIN_WARP_FRACTAL_NONE);
        CHECK(noiselite->get_domain_warp_fractal_type() == noiselite->DOMAIN_WARP_FRACTAL_NONE);

        noiselite->set_domain_warp_fractal_type(noiselite->DOMAIN_WARP_FRACTAL_NONE);
        CHECK(noiselite->get_domain_warp_fractal_type() == noiselite->DOMAIN_WARP_FRACTAL_NONE);

        noiselite->set_domain_warp_fractal_type(noiselite->DOMAIN_WARP_FRACTAL_INDEPENDENT);
        CHECK(noiselite->get_domain_warp_fractal_type() == noiselite->DOMAIN_WARP_FRACTAL_INDEPENDENT);
    }

    // Interface Methods

    TEST_CASE("[FastNoiseLite] Interface Methods: getNoise1D, 2Dv, 3Dv") {
        Ref<FastNoiseLite> noiselite = memnew(FastNoiseLite());
        fastnoiselite::FastNoiseLite _noise = fastnoiselite::FastNoiseLite();

        Vector3 offset = Vector3(0.3, 0.3, 0.3);
        Vector2 offset2 = Vector2(1, 1);
        noiselite->set_offset(offset);

        //NOISE 1D

        _noise.SetFractalType(_noise.FractalType_None);
        _noise.SetNoiseType(_noise.NoiseType_OpenSimplex2);

        CHECK(noiselite->get_noise_1d(real_t(0.5)) == real_t(noiselite->get_noise_2d(real_t(0.5+offset.x), real_t(0.0))));

        // NOISE 2Dv

        _noise.SetFractalType(_noise.FractalType_None);
        _noise.SetNoiseType(_noise.NoiseType_OpenSimplex2);

        CHECK(noiselite->get_noise_2dv(offset2) == real_t(noiselite->get_noise_2d(offset2.x, offset2.y)));

        // NOISE 3Dv

        _noise.SetFractalType(_noise.FractalType_None);
        _noise.SetNoiseType(_noise.NoiseType_OpenSimplex2);

        CHECK(noiselite->get_noise_3dv(offset) == real_t(noiselite->get_noise_3d(offset.x, offset.y, offset.z)));
    }


} // namespace TestFastNoiseLite

#endif // TEST_FASTNOISELITE_H
